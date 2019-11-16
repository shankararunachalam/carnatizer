// -----------------------------------------------------------------------------
// controller - the glue between the engine and the hardware
//
// reacts to events (grid press, clock etc) and translates them into appropriate
// engine actions. reacts to engine updates and translates them into user 
// interface and hardware updates (grid LEDs, CV outputs etc)
//
// should talk to hardware via what's defined in interface.h only
// should talk to the engine via what's defined in engine.h only
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <inttypes.h>
#include <malloc.h>
#include <math.h>
#include "string.h"
#include "delay.h"

#include "control.h"
#include "interface.h"
#include "engine.h"
#include "music.h"
#include "raagas.c"
#include "ratios.c"
#include "files/sarali.c"

const u16 RAGA_CHOICE_COUNT = 72;
const u16 PLAY_CHOICE_COUNT = 2;

preset_meta_t meta;
preset_data_t preset;
shared_data_t shared;
int selected_preset;

//general params
int selected_raga;
int selected_play_choice;
int used_play_mode;

enum state_opts {
    INIT,
    RAGA_CHOICE,
    PLAY_CHOICE,
    PLAY_FILE,
    PLAY_GRID
};
enum state_opts state;

//file play params
enum direction_opts {
    AAROHANA,
    AVAROHANA
};
enum direction_opts current_direction;
int sarali_length;
int current_sarali_row;
int current_sthana_position;
int empty_swara_played;

// ----------------------------------------------------------------------------
// firmware dependent stuff starts here

// ----------------------------------------------------------------------------
// prototypes

static void display(char *text, u8 line);
static void highlight(char *text, u8 line);
static void display_text(char *text, char *text_value, u8 line);
static void display_value(char *text, u16 value, u8 line);
static void display_line(u8 hasValue, char *text, u16 value, u8 line, u8 isHighlight);

static void display_raga_choices(u16 selection);
static void display_play_choices(u16 selection);
static void display_play_grid_screen(void);
static void display_play_file_screen(void);

static u16 calculate_cv(u8 row, u8 col, u8 direction);
static u16 calculate_knob_value(u16 divisions);
static void set_state(int state_value);
static void play_swara(void);

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// helper functions

void display(char *text, u8 line) {
    display_line(0, text, 0, line, 0);
}

void highlight(char *text, u8 line) {
    display_line(0, text, 0, line, 1);
}

void display_text(char *text, char *text_value, u8 line) {
    u16 length = strlen(text) + strlen(text_value);
    char *buffer = malloc( sizeof(char) * ( length + 1 ) );
    strcpy(buffer, text);
    strcat(buffer, text_value);
    display_line(0, buffer, 0, line, 0);
}

void display_value(char *text, u16 value, u8 line) {
    display_line(1, text, value, line, 0);
}

void display_line(u8 hasValue, char *text, u16 value, u8 line, u8 isHighlight) {
    u16 length = strlen(text) + 1;
    if(hasValue == 1) {
        length = length + 1 + 10; //length of text plus space plus length of u16 value
    }
    u8 foreground = 255;
    u8 background = 0;
    char *buffer = malloc( sizeof(char) * ( length + 1 ) );
    if(hasValue == 1) {
        snprintf(buffer, length, "%s %hu", text, value);
    } else {
        snprintf(buffer, length, "%s", text);
    }
    if(isHighlight == 1) {
        background = 70;
    }
    draw_str(buffer, line, foreground, background);
    refresh_screen();
}

void display_raga_choices(u16 selection) {
    clear_screen();
    for(int i = 0; i < 6; i++) {
        if(selection + i > 71) {
            display("", i);
        } else {
            if(i == 0) {
                highlight((char *)melakartha_raga[selection + i].name, i);
            } else {
                display((char *)melakartha_raga[selection + i].name, i);
            }
        }
    }
    display("  Select", 7);
}

void display_play_choices(u16 selection) {
    clear_screen();
    if(selection == 0) {
        highlight((char *)"Play File", 0);
        display((char *)"Play Grid", 1);
    } else {
        display((char *)"Play File", 0);
        highlight((char *)"Play Grid", 1);
    }
    display("  Select", 7);
}

static void display_play_grid_screen() {
    clear_screen();
    display_text("Playing raaga: ", (char *)melakartha_raga[selected_raga].name, 0);
    clear_all_grid_leds();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 7; j++) {
            set_grid_led(j, i, 100);
        }
    }
    refresh_grid();    
    display("   Back", 7);
}

static void display_play_file_screen() {
    clear_screen();
    display("Playing file: ", 0);
    display("   Back", 7);
}

u16 calculate_cv(u8 sthana, u8 octave, u8 direction) {
    u8 numerator = 1, denominator = 1;
    const char *swara = melakartha_raga[selected_raga].aarohana_note[sthana];
    if(direction == AVAROHANA) {
        swara = melakartha_raga[selected_raga].avarohana_note[sthana];
    }
    display_text("Swara: ", (char *)swara, 5);
    for(int i = 0; i < 17; i++) {
        if(strcmp(swarasthanas[i].name, swara) == 0) {
            numerator = swarasthanas[i].numerator;
            denominator = swarasthanas[i].denominator;
            break;
        }
    }
    u16 cv = (409 * octave) + (409 * numerator / denominator); // 4092 / 10 octaves is 409 per octave
    //display_value("Swara value: ", cv, 6);
    return cv;
}

u16 calculate_knob_value(u16 divisions) {
    u16 knob_value = get_knob_value(0);
    knob_value = (knob_value / 65536.0) * divisions; //to get a value between 1 and divisions. 66536 is the max.
    return knob_value;
}

void set_state(int state_value) {
    switch(state_value) {
        case RAGA_CHOICE:
            selected_raga = -1;
            selected_play_choice = -1;
            break;
        case PLAY_CHOICE:
            selected_play_choice = -1;
            break;
        case PLAY_GRID:
            used_play_mode = -1;
            break;
        case PLAY_FILE:
            used_play_mode = -1;
            sarali_length = sizeof(sarali) / sizeof(sarali[0]);
            current_sarali_row = 0;
            current_direction = AAROHANA;
            current_sthana_position = 0;
            empty_swara_played = 0;
            break;
    }
    state = state_value;
}

void play_swara() {
    used_play_mode = 1;
    set_gate(0, 0);
    char aarohana_sthanas[8] = {'S', 'R', 'G', 'M', 'P', 'D', 'N', 'Z'};
    char avarohana_sthanas[8] = {'Z', 'N', 'D', 'P', 'M', 'G', 'R', 'S'};
    char current_sthana = '\0';
    u8 next_octave = 0;
    const char *current_sarali = sarali[current_sarali_row].aarohana;
    if(current_direction == AVAROHANA) {
        current_sarali = sarali[current_sarali_row].avarohana;
    }
    if(current_sarali[current_sthana_position] != '\0') {
        u8 pos = 0;
        current_sthana = current_sarali[current_sthana_position];
        if(current_sarali[current_sthana_position + 1] != '\0' && current_sarali[current_sthana_position + 1] == '.') {
            next_octave = 1;
            current_sthana_position++;
        }
        if(current_sarali[current_sthana_position] != ',') {
            for(int j = 0; j < 8; j++) {
                if(current_direction == AVAROHANA) {
                    if(avarohana_sthanas[j] == current_sthana) {
                        pos = j;
                        if(next_octave == 1) {
                            next_octave = 0;
                            pos = 0;
                        }
                        break;
                    }
                } else {
                    if(aarohana_sthanas[j] == current_sthana) {
                        pos = j;
                        if(next_octave == 1) {
                            next_octave = 0;
                            pos = 7;
                        }
                        break;  
                    }
                }
            }
            set_cv(0, calculate_cv(pos, 3, current_direction) << 2);
            set_gate(0, 1);
        }
        current_sthana_position++;
    } else {
        if(empty_swara_played < 2) {
            empty_swara_played++;
        } else {
            empty_swara_played = 0;
            current_sthana_position = 0;
            if(current_direction == AAROHANA) {
                current_direction = AVAROHANA;
            } else {
                current_sarali_row++;
                if(current_sarali_row == sarali_length) {
                    display("Finished playing file. ", 0);
                    display(" ", 5);
                }
                current_direction = AAROHANA;
            }
        }
    }
}

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// functions for main.c

void init_presets(void) {
    // called by main.c if there are no presets saved to flash yet
    // initialize meta - some meta data to be associated with a preset, like a glyph
    // initialize shared (any data that should be shared by all presets) with default values
    // initialize preset with default values 
    // store them to flash
    
    for (u8 i = 0; i < get_preset_count(); i++) {
        store_preset_to_flash(i, &meta, &preset);
    }

    store_shared_data_to_flash(&shared);
    store_preset_index(0);
}

void init_control(void) {
    // load shared data
    // load current preset and its meta data
    
    load_shared_data_from_flash(&shared);
    selected_preset = get_preset_index();
    load_preset_from_flash(selected_preset, &preset);
    load_preset_meta_from_flash(selected_preset, &meta);

    // set up any other initial values and timers

    //timed event for knob adjustment
    add_timed_event(0, 50, 1);
    
    //initial display
    selected_raga = calculate_knob_value(RAGA_CHOICE_COUNT);
    display_raga_choices(selected_raga);
    set_state(RAGA_CHOICE);
}

void process_event(u8 event, u8 *data, u8 length) {
    if(event != 0 || (event == 0 && data[0] == 0)) {
        int display = event;
        if(event == 0) {
            display = data[1];
        }
        //display_value("Event: ", event, 6);
    }
    switch (event) {
        case MAIN_CLOCK_RECEIVED:
            if(state == PLAY_FILE && current_sarali_row < sarali_length) {
                play_swara();
            }
            break;
        
        case MAIN_CLOCK_SWITCHED:
            break;
    
        case GATE_RECEIVED:
            break;
        
        case GRID_CONNECTED:
            break;
        
        case GRID_KEY_PRESSED:
        {
            if(state == PLAY_GRID) {
                display_value("data[0]:", data[0], 1);
                display_value("data[1]:", data[1], 2);
                display_value("data[2]:", data[2], 3);
                display_value("data[3]:", data[3], 4);
                if(data[2] == 1) {
                    set_cv(0, calculate_cv(6 - data[0], data[1], 0) << 2); //weird grid 0 is rightmost
                    set_gate(0, 1);
                } else {
                    set_cv(0, 0);
                    set_gate(0, 0);
                }
            }
            break;
        }
    
        case GRID_KEY_HELD:
        {
            display_value("held data[0]:", data[0], 1);
            display_value("held data[1]:", data[1], 2);
            display_value("held data[2]:", data[2], 3);
            display_value("held data[3]:", data[3], 4);
            break;
        }
            
        case ARC_ENCODER_COARSE:
            break;
    
        case FRONT_BUTTON_HELD:
        case FRONT_BUTTON_PRESSED:
        {
            if(data[0] > 0) {
                switch(state) {
                    case RAGA_CHOICE:
                    {
                        if(selected_raga != -1) {
                            display_play_choices(selected_play_choice);
                            set_state(PLAY_CHOICE);
                        }
                        break;
                    }
                    case PLAY_CHOICE:
                    {
                        if(selected_play_choice == 1) {
                            display_play_grid_screen();
                            set_state(PLAY_GRID);
                        } else if(selected_play_choice == 0) {
                            display_play_file_screen();
                            set_state(PLAY_FILE);
                        }
                        break;
                    }
                    case PLAY_FILE:
                    {
                        if(used_play_mode != -1) {
                            selected_raga = calculate_knob_value(RAGA_CHOICE_COUNT);
                            display_raga_choices(selected_raga);
                            set_state(RAGA_CHOICE);
                        }
                        break;
                    }
                    case PLAY_GRID:
                    {
                        if(used_play_mode != -1) {
                            clear_all_grid_leds();
                            refresh_grid();
                            selected_raga = calculate_knob_value(RAGA_CHOICE_COUNT);
                            display_raga_choices(selected_raga);
                            set_state(RAGA_CHOICE);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            break;
        }
    
        case I2C_RECEIVED:
            break;
            
        case TIMED_EVENT:
        {
            if (data[0] == 0) {
                switch(state) {
                    case RAGA_CHOICE:
                    {
                        u16 knob_value = calculate_knob_value(RAGA_CHOICE_COUNT);
                        if(selected_raga != knob_value) {
                            selected_raga = knob_value;
                            display_raga_choices(selected_raga);
                        }
                        break;
                    }
                    case PLAY_CHOICE:
                    {
                        u16 knob_value = calculate_knob_value(PLAY_CHOICE_COUNT);
                        if(selected_play_choice != knob_value) {
                            selected_play_choice = knob_value;
                            display_play_choices(selected_play_choice);
                        }
                        break;
                    }
                    case PLAY_FILE:
                    {
                        break;
                    }
                    case PLAY_GRID:
                    {
                        used_play_mode = 1;
                        break;
                    }
                    default:
                        break;
                }
            }
            break;
        }
        
        case MIDI_CONNECTED:
            break;
        
        case MIDI_NOTE:
        {
            // play a note when a MIDI note is received
            note(data[0], data[1], data[2], data[3]);
            display_value("Midi voice:", data[0], 1);
            display_value("Midi note:", data[1], 2);
            display_value("Midi volume:", data[2], 3);
            display_value("Midi on:", data[3], 4);
            break;
        }
        
        case MIDI_CC:
            break;
            
        case MIDI_AFTERTOUCH:
            break;
            
        case SHNTH_BAR:
            break;
            
        case SHNTH_ANTENNA:
            break;
            
        case SHNTH_BUTTON:
            break;
            
        default:
            break;
    }
}

void render_grid(void) {
    // render grid LEDs here or leave blank if not used
}

void render_arc(void) {
    // render arc LEDs here or leave blank if not used
}

