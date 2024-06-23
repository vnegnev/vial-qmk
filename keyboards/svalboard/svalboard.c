#include "svalboard.h"
#include "eeconfig.h"

saved_values_t global_saved_values;

void write_eeprom_kb(void) {
    eeconfig_update_kb_datablock(&global_saved_values);
}

void read_eeprom_kb(void) {
    bool modified = false;
    eeconfig_read_kb_datablock(&global_saved_values);
    if (global_saved_values.version < 1) {
        global_saved_values.version = 1;
        global_saved_values.right_dpi_index=2;
        global_saved_values.left_dpi_index=2;
        modified = true;
    }
    if (global_saved_values.version < 2) {
        global_saved_values.version = 2;
        global_saved_values.mh_timer_index = 2;
        modified = true;
    }
    if (global_saved_values.version < 3) {
	global_saved_values.version = 3;
	global_saved_values.am_threshold = 0x05; // disabled; default value of 5
	modified = true;
    }
    // As we add versions, just append here.
    if (modified) {
        write_eeprom_kb();
    }
}

const uint16_t dpi_choices[] = { 200, 400, 800, 1200, 1600, 2400 }; // If we need more, add them.
#define DPI_CHOICES_LENGTH (sizeof(dpi_choices)/sizeof(dpi_choices[0]))

void increase_left_dpi(void) {
    if (global_saved_values.left_dpi_index + 1 < DPI_CHOICES_LENGTH) {
        global_saved_values.left_dpi_index++;
        set_left_dpi(global_saved_values.left_dpi_index);
        write_eeprom_kb();
    }
}

void decrease_left_dpi(void) {
    if (global_saved_values.left_dpi_index > 0) {
        global_saved_values.left_dpi_index--;
        set_left_dpi(global_saved_values.left_dpi_index);
        write_eeprom_kb();
    }
}

void increase_right_dpi(void) {
    if (global_saved_values.right_dpi_index + 1 < DPI_CHOICES_LENGTH) {
        global_saved_values.right_dpi_index++;
        set_right_dpi(global_saved_values.right_dpi_index);
        write_eeprom_kb();
    }
}

void decrease_right_dpi(void) {
    if (global_saved_values.right_dpi_index > 0) {
        global_saved_values.right_dpi_index--;
        set_right_dpi(global_saved_values.right_dpi_index);
        write_eeprom_kb();
    }
}
// TODO: Still need to add code to save values.
void set_left_dpi(uint8_t index) {
    uprintf("LDPI: %d %d\n", index, dpi_choices[index]);
    pointing_device_set_cpi_on_side(true, dpi_choices[index]);
}

void set_right_dpi(uint8_t index) {
    uprintf("RDPI: %d %d\n", index, dpi_choices[index]);
    pointing_device_set_cpi_on_side(false, dpi_choices[index]);
}

void set_dpi_from_eeprom(void) {
    read_eeprom_kb();
    set_left_dpi(global_saved_values.left_dpi_index);
    set_right_dpi(global_saved_values.right_dpi_index);
}

void keyboard_post_init_kb(void) {
    set_dpi_from_eeprom();
    keyboard_post_init_user();
}

#ifndef SVALBOARD_REENABLE_BOOTMAGIC_LITE
// This is to override `bootmagic_lite` feature (see docs/feature_bootmagic.md),
// which can't be turned off in the usual way (via info.json) because setting
// `VIA_ENABLE` forces `BOOTMAGIC_ENABLE` in `builddefs/common_features.mk`.
//
// Obviously if you find this feature useful, you might want to define the
// SVALBOARD_... gating macro, and then possibly also (re-)define the
// `"bootmagic": { "matrix": [X,Y] },` in `info.json` to point the matrix at
// a more useful key than the [0,0] default. Ideally a center key, which is
// normally ~always present. Because the default (thumb knuckle) means that
// if you boot with the key pulled out, the eeprom gets cleared.

void bootmagic_lite(void) {
  // boo!
}
#endif

__attribute__((weak)) void recalibrate_pointer(void) {
}
