// ----------------------------------------------------------------------------
// fake main.c implementation to simulate multipass interaction with hardware
//
// implements functions that provide fake access to the hardware (inputs, outputs, 
// knobs, MIDI, grid, arc etc) as defined in interface.h
//
// fakes sending hardware events to controller
//
// provides fake preset management for persistent memory (flash/USB)
//
// based on monome eurorack code: https://github.com/monome
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>

#include "interface.h"
#include "control.h"

// ----------FOR TELETYPE
// ----------------------------------------------------------------------------
// knobs

#define _HARDWARE_KNOB_COUNT 1
const u8 _hardware_knob_ids[_HARDWARE_KNOB_COUNT] = { 0 };


// ----------------------------------------------------------------------------
// buttons (not including the main button, reserved for presets/global config)

#define _HARDWARE_BUTTON_COUNT 0
const u8 _hardware_button_pins[_HARDWARE_BUTTON_COUNT] = { };


// ----------------------------------------------------------------------------
// inputs

#define _POLL_INPUTS 1

#define _HARDWARE_CV_INPUT_COUNT 1
#define _HARDWARE_GATE_INPUT_COUNT 8

#define _HARDWARE_CLOCK_INPUT 0
const u8 _hardware_clock_detect_pin;


// ----------------------------------------------------------------------------
// outputs

#define _HARDWARE_CLOCK_OUTPUT 0
const u8 _hardware_clock_output_pin;

#define _HARDWARE_CV_OUTPUT_COUNT 4
#define _HARDWARE_CV_DAISY_CHAINED 1

#define _HARDWARE_GATE_OUTPUT_COUNT 4
#define _HARDWARE_GATE_OUTPUT_PIN 1

// ----------------------------------------------------------------------------
// other

#define _HARDWARE_LED_COUNT 0
#define _HARDWARE_SCREEN 1

//-----------TELETYPE END

#define ADC_COUNT 4
#define MAX_CV_COUNT 4
#define MAX_GATE_COUNT 8

static u16 adc_values[ADC_COUNT];

static u8 front_button_pressed;
static u8 button_pressed[_HARDWARE_BUTTON_COUNT];

static s16 cv_input_values[_HARDWARE_CV_INPUT_COUNT];
static u8 gate_input_values[_HARDWARE_GATE_INPUT_COUNT];
static s16 cv_values[MAX_CV_COUNT];

// ----------------------------------------------------------------------------
// timers

void add_timed_event(uint8_t index, uint16_t ms, uint8_t repeat) {
}
void stop_timed_event(uint8_t index) {
}


// ----------------------------------------------------------------------------
// clock

uint64_t get_global_time(void) {
    return 0;
}
uint8_t is_external_clock_connected(void) {
    return 0;
}
void set_clock_output(uint8_t on) {
}


// ----------------------------------------------------------------------------
// inputs

uint8_t get_cv_input_count(void) {
    return _HARDWARE_CV_INPUT_COUNT;
}
int16_t get_cv(uint8_t index) {
    if (index >= _HARDWARE_CV_INPUT_COUNT) return 0;
    return cv_input_values[index];
}

uint8_t get_gate_input_count(void) {
    return _HARDWARE_GATE_INPUT_COUNT;
}
uint8_t get_gate(uint8_t index) {
    if (index >= _HARDWARE_GATE_INPUT_COUNT) return 0;
    return gate_input_values[index];
}


// ----------------------------------------------------------------------------
// outputs

uint8_t get_cv_output_count(void) {
    return _HARDWARE_CV_OUTPUT_COUNT;  
}
void set_cv(uint8_t output, int16_t value) {
    if (output >= _HARDWARE_CV_OUTPUT_COUNT || output >= MAX_CV_COUNT) return;
    cv_values[output] = value;
}

uint8_t get_gate_output_count(void) {
    return _HARDWARE_GATE_OUTPUT_COUNT;
}
void set_gate(uint8_t output, uint8_t on) {
    if (output >= _HARDWARE_GATE_OUTPUT_COUNT || output >= MAX_GATE_COUNT) return;
}


// ----------------------------------------------------------------------------
// controls

uint8_t get_button_count(void) {
    return _HARDWARE_BUTTON_COUNT;
}
uint8_t is_button_pressed(uint8_t index) {
    if (index >= _HARDWARE_BUTTON_COUNT) return 0;
    return button_pressed[index];
}

uint8_t get_knob_count(void) {
    return _HARDWARE_KNOB_COUNT;
}
uint16_t get_knob_value(uint8_t index) {
    if (index >= _HARDWARE_KNOB_COUNT || index >= ADC_COUNT) return 0;
    return adc_values[_hardware_knob_ids[index]] << 4;
}


// ----------------------------------------------------------------------------
// grid/arc

uint8_t is_grid_connected(void) {
    return 0;
}
uint8_t get_grid_column_count(void) {
    return 0;
}
uint8_t get_grid_row_count(void) {
    return 0;
}
uint8_t is_grid_vb(void) {
    return 0;
}

void clear_all_grid_leds(void) {
}
void set_grid_led(uint8_t x, uint8_t y, uint8_t level) {
}
void set_grid_led_i(uint16_t index, uint8_t level) {
}
void refresh_grid(void) {
}

uint8_t is_arc_connected(void) {
    return 0;
}
uint8_t get_arc_encoder_count(void) {
    return 0;
}

void clear_all_arc_leds(void) {
}
void set_arc_led(uint8_t enc, uint8_t led, uint8_t level) {
}
void refresh_arc(void) {
}


// ----------------------------------------------------------------------------
// midi

uint8_t is_midi_connected(void) {
    return 0;
}


// ----------------------------------------------------------------------------
// notes

void note(uint8_t voice, uint16_t note, uint16_t volume, uint8_t on) {
}
void note_v(uint8_t voice, int16_t pitch, uint16_t volume, uint8_t on) {
}
void note_on(uint8_t voice, uint16_t note, uint16_t volume) {
}
void note_on_v(uint8_t voice, int16_t pitch, uint16_t volume) {
}
void note_off(uint8_t voice) {
}

void map_voice(uint8_t voice, uint8_t device, uint8_t output, uint8_t on) {
}
void set_output_transpose(uint8_t device, uint16_t output, uint16_t note) {
}
void set_output_transpose_v(uint8_t device, uint16_t output, int16_t pitch) {
}
void set_output_max_volume(uint8_t device, uint16_t output, uint16_t volume) {
}


// ----------------------------------------------------------------------------
// i2c / devices

void mute_device(uint8_t device, uint8_t mute) {
}

void set_as_i2c_leader(void) {
}
void set_as_i2c_follower(uint8_t address) {
}

void set_er301_cv(uint8_t output, int16_t value) {
}
void set_er301_gate(uint8_t output, uint8_t on) {
}

void set_jf_mode(uint8_t mode) {
}
void set_jf_gate(uint8_t output, uint8_t on) {
}

void set_txo_mode(uint8_t output, uint8_t mode) {
}
void set_txo_cv(uint8_t output, int16_t value) {
}
void set_txo_gate(uint8_t output, uint8_t on) {
}

void set_txo_attack(uint8_t output, uint16_t attack) {
}
void set_txo_decay(uint8_t output, uint16_t decay) {
}
void set_txo_waveform(uint8_t output, uint16_t waveform) {
}


// ----------------------------------------------------------------------------
// flash storage

uint8_t is_flash_new(void) {
    return 0;
}
uint8_t get_preset_index(void) {
    return 0;
}
uint8_t get_preset_count(void) {
    return 0;
}

void store_preset_to_flash(uint8_t index, preset_meta_t *meta, preset_data_t *preset) {
}
void store_preset_index(uint8_t index) {
}
void store_shared_data_to_flash(shared_data_t *shared) {
}

void load_preset_from_flash(uint8_t index, preset_data_t *preset) {
}
void load_preset_meta_from_flash(uint8_t index, preset_meta_t *meta) {
}
void load_shared_data_from_flash(shared_data_t *shared) {
}


// ----------------------------------------------------------------------------
// screen

void clear_screen(void) {
}
void fill_line(uint8_t line, uint8_t colour) {
}
void draw_str(const char* str, uint8_t line, uint8_t colour, uint8_t background) {
}
void refresh_screen(void) {
}


// ----------------------------------------------------------------------------
// other

void set_led(uint8_t index, uint8_t level) {
}
void set_debug(uint8_t on) {
}
void print_debug(const char *str) {
}
void print_int(const char *str, int16_t value) {
}