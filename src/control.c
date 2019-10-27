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
#include "string.h"

#include "control.h"
#include "interface.h"
#include "engine.h"

preset_meta_t meta;
preset_data_t preset;
shared_data_t shared;
int selected_preset;
int selected_raga;
enum state_opts {
    INIT,
    SELECT,
    PLAY
};

enum state_opts state;

// ----------------------------------------------------------------------------
// firmware dependent stuff starts here

// ----------------------------------------------------------------------------
// prototypes

static void display_text(char *text, u8 line);
static void display(char *text, u16 value, u8 line);
static void highlight_text(char *text, u8 line);
static void highlight(char *text, u16 value, u8 line);
static void display_line(u8 hasValue, char *text, u16 value, u8 line, u8 isHighlight);

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// helper functions

void display_text(char *text, u8 line) {
    display_line(0, text, 0, line, 0);
}

void display(char *text, u16 value, u8 line) {
    display_line(1, text, value, line, 0);
}

void highlight_text(char *text, u8 line) {
    display_line(0, text, 0, line, 1);
}

void highlight(char *text, u16 value, u8 line) {
    display_line(1, text, value, line, 1);
}

void display_line(u8 hasValue, char *text, u16 value, u8 line, u8 isHighlight) {
    u16 length = strlen(text);
    if(hasValue == 1) {
        length = length + 1 + 5; //length of text plus space plus length of u8 value
    }
    u8 foreground = 255;
    u8 background = 0;
    if(isHighlight == 1) {
        foreground = 0;
        background = 255;
    }
    char *buffer = malloc( sizeof(char) * ( length + 1 ) );
    if(hasValue == 1) {
        snprintf(buffer, length, "%s %u", text, value);
    } else {
        snprintf(buffer, length, "%s", text);
    }
    draw_str(buffer, line, foreground, background);
    refresh_screen();
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

    state = INIT;
    //timed event for knob adjustment
    add_timed_event(0, 50, 1);

    display_text("Carnatizer.", 0);
    display_text("Press button to select Raga ->", 2);
}

void process_event(u8 event, u8 *data, u8 length) {
    switch (event) {
        case MAIN_CLOCK_RECEIVED:
            break;
        
        case MAIN_CLOCK_SWITCHED:
            break;
    
        case GATE_RECEIVED:
            break;
        
        case GRID_CONNECTED:
            break;
        
        case GRID_KEY_PRESSED:
            break;
    
        case GRID_KEY_HELD:
            break;
            
        case ARC_ENCODER_COARSE:
            break;
    
        case FRONT_BUTTON_PRESSED:
            if(state == INIT) {
                state = SELECT;
            }
            break;
    
        case FRONT_BUTTON_HELD:
            break;
    
        case BUTTON_PRESSED:
            break;
    
        case I2C_RECEIVED:
            break;
            
        case TIMED_EVENT:
            if (data[0] == 0) {
                switch(state) {
                    case INIT:
                        break;
                    case SELECT:
                    {
                        u16 knobValue = get_knob_value(0);
                        knobValue = (knobValue / 65536.0) * 72; //to get a value between 1 and 72. 66536 is the max.
                        if(knobValue != selected_raga) {
                            selected_raga = knobValue;
                        }
                        display("Selected raga:", selected_raga, 5);
                        break;
                    }
                    case PLAY:
                        break;
                    default:
                        break;
                }
            }
            break;
        
        case MIDI_CONNECTED:
            break;
        
        case MIDI_NOTE:
            // play a note when a MIDI note is received
            note(data[0], data[1], data[2], data[3]);
            display("Midi voice:", data[0], 1);
            display("Midi note:", data[1], 2);
            display("Midi volume:", data[2], 3);
            display("Midi on:", data[3], 4);
            break;
        
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

