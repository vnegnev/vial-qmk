/*
Copyright 2023 Morgan Venable @_claussen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>

void keyboard_post_init_user(void) {
  // Customise these values if you need to debug the matrix
  //debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// in keymap.c:
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(5); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
#endif

enum my_keycodes {
  KC_NORMAL_HOLD = SAFE_RANGE,
  KC_FUNC_HOLD
};

enum layer {
    NORMAL,
    NORMAL_HOLD,
    NAS,
    FUNC,
    FUNC_HOLD,
    MBO,
    NUM_LAYERS
};

const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
 [NORMAL] = LAYOUT(
             /*Center           North           East            South           West*/
        
                    /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
    ),

    [NORMAL_HOLD] = LAYOUT(
             /*Center           North           East            South           West*/
                  /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
    ),

    [NAS] = LAYOUT(
             /*Center           North           East            South           West*/
                   /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
    ),

    [FUNC] = LAYOUT(
             /*Center           North           East            South           West*/
                    /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
    ),

    [FUNC_HOLD] = LAYOUT(
             /*Center           North           East            South           West*/
                    /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
    ),
    
    [MBO] = LAYOUT(
             /*Center           North           East            South           West*/
                    /*Center           North           East            South           West*/
        /*R1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*R4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L1*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L2*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L3*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*L4*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,
        /*RT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO,
        /*LT*/ KC_NO,            KC_NO,           KC_NO,           KC_NO,           KC_NO,   KC_NO
        )

};


#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
void mouse_mode(bool);

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

      // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
    if (mh_auto_buttons_timer) {
      switch (keycode) {
      case KC_BTN1:
      case KC_BTN2:
      case KC_BTN3:
      case KC_WH_U:
      case KC_WH_D:
	break;
      default:
	mouse_mode(false);
      }
    }
#endif

  switch (keycode) {

     case KC_NORMAL_HOLD:
/*      if (record->event.pressed) {
          layer_clear();
          layer_on(NORMAL_HOLD);
          SEND_STRING(SS_LCTL(SS_TAP(X_F19)));
      } else {
          layer_off(NORMAL_HOLD);
      }
      return false;
      */
      
/*     case KC_FUNC_HOLD:
      if (record->event.pressed) {
          layer_clear();
          layer_on(FUNC_HOLD);
      } else {
          layer_off(FUNC_HOLD);
      }
      return false;*/
      return false;
    default:
      return true;
  }
};

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      mouse_mode(true);
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: on\n");
  #endif
    }
  }
}

void matrix_scan_user(void) {
  if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      mouse_mode(false);
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: off\n");
  #endif
    }
  }
}

void mouse_mode(bool on) {
  if (on) {
    layer_on(MH_AUTO_BUTTONS_LAYER);
    mh_auto_buttons_timer = timer_read();
  } else {
    layer_off(MH_AUTO_BUTTONS_LAYER);
    mh_auto_buttons_timer = 0;
  }
}

#endif // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE