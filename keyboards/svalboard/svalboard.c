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

void pointing_device_init_kb(void) {
    read_eeprom_kb();
    set_left_dpi(global_saved_values.left_dpi_index);
    set_right_dpi(global_saved_values.right_dpi_index);
}

void keyboard_post_init_kb(void) {
    pointing_device_init_kb();
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

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"

void ps2_mouse_init_user() {
//sensitivity command in fourth byte 00 = 0 multiplier, FF = 2.0 multiplier
  /*
    PS2_MOUSE_SEND(0xE2);
    PS2_MOUSE_SEND(0x81);
    PS2_MOUSE_SEND(0x4A);
    PS2_MOUSE_SEND(0x59);
    */
//Z tap -- doesn't seem to work.  0x01 is on.
  uint8_t val;

  ps2_mouse_disable_data_reporting();

  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
  PS2_MOUSE_SEND(0x47, "pts: 0x47");
  PS2_MOUSE_SEND(0x2C, "pts: 0x2C");
  PS2_MOUSE_SEND(0x00, "pts: 0x00");  // 01 turns on Z tap, 00 turns off
  PS2_MOUSE_RECEIVE("ztap - disable");

/*
From Sprintek:

E2 47 FA 10 - Disable drift correction. - Flips the bit, it should boot enabled.

This was given to us to stop the trackpoint from calibrating at bad times.

*/

  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
  PS2_MOUSE_SEND(0x80, "pts: 0x80");
  PS2_MOUSE_SEND(0xFA, "pts: 0xFA");
  val = ps2_host_recv_response();

  if (~val & 0x10) {
      PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
      PS2_MOUSE_SEND(0x47, "pts: 0x47");
      PS2_MOUSE_SEND(0xFA, "pts: 0xFA");
      PS2_MOUSE_SEND(0x10, "pts: 0x10");
      PS2_MOUSE_RECEIVE("drift correction - disable");
  }
/*

From Sprintek:

E2 81 92 XX - Set the deadzone - 0x0C default, claimed.

Increase this to get rid of the tail drift.

*/
//  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
//  PS2_MOUSE_SEND(0x81, "pts: 0x81");
//  PS2_MOUSE_SEND(0x92, "pts: 0x92");
//  PS2_MOUSE_SEND(0x80, "pts: 0x0C");  // Experiment with this if it isn't enough.

/*

Timing on the double tap on the trackpoint:

E2 80 5E
E2 81 5E XX

Z Time Constant [zTc]
 This PtS parameter is the time constant of the running average of Z force.  Its units are in
 force sampling time units as specified in the Set Sampling Rate command on page 14.
 This determines how sharp a press has to be to be recognized.  The value of this parameter
 is 256/n, where n is the desired time constant.  The running average is then calculated with
 the formula:
  where A = running average, N = present sample, and X is
 A=A+(N−A) X
 256
 zTc.  The default value for zTc is x"26" (decimal 38) corresponding to a time constant of
 6.7 samples.  This value is not affected by a reset (x"FF") or set default (x"F6") command

*/


    PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
    PS2_MOUSE_SEND(0x81, "pts: 0x81");
    PS2_MOUSE_SEND(0x5E, "pts: 0x5E");
    PS2_MOUSE_SEND(0x00, "pts: 0x00");
    PS2_MOUSE_RECEIVE("double Z tap - disable");

    ps2_mouse_enable_data_reporting();

}
#endif

void recalibrate_pointer(void) {
#ifdef PS2_MOUSE_ENABLE
    PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
    PS2_MOUSE_SEND(0x51, "pts: 0x51");
    PS2_MOUSE_RECEIVE("trackpoint - recalibrate");
#endif
}

