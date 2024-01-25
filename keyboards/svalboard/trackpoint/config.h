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

#pragma once

/* key matrix size */
// Rows are doubled-up

// wiring of each half
//Layout for svalboard v0 (different from lalboard_v2)
//1 2 3 4 5 6
//S E D N W None
//Both Thumbs (these are same as lalboard_v2)
//OL OU D IL MODE DOUBLE
//Knuckle Nail Down Pad Up Double
//#define THUMB_DOWN_ACTIVE_DARK

#ifndef MATRIX_COL_PUSHED_STATES
#define MATRIX_COL_PUSHED_STATES { 0, 0, 1, 0, 0, 0 }
#endif
#ifndef MATRIX_COL_PUSHED_STATES_THUMBS
  #ifdef THUMB_DOWN_ACTIVE_DARK
      #define MATRIX_COL_PUSHED_STATES_THUMBS { 0, 0, 1, 0, 0, 0 }
  #else
      #define MATRIX_COL_PUSHED_STATES_THUMBS { 0, 0, 0, 0, 0, 0 }
  #endif
#endif

//PS2 Trackpoint Setup
#ifdef PS2_MOUSE_ENABLE
  //#define SERIAL_PIO_USE_PIO1
  #define PS2_PIO_USE_PIO1
  #define PS2_RESET_PIN GP25
  #define PS2_CLOCK_PIN GP24
  #define PS2_DATA_PIN GP23
  #define PS2_MOUSE_SCROLL_DIVISOR_H 4
  #define PS2_MOUSE_SCROLL_DIVISOR_V 4
  #ifndef PS2_MOUSE_ROTATE
  #define PS2_MOUSE_ROTATE 90 
  //default is N exit on right hand --270 for N on left see bsa.sh
  #endif
//  #define PS2_MOUSE_SCROLL_BTN_MASK 0  // just normal middle button for panning and relative scroll
  #define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE) /* Default -- tap to enter relative scroll, hold to use direct scroll*/ 
#endif

//@manna-harbour's automousekeys
#if defined MH_AUTO_BUTTONS
  #define MH_AUTO_BUTTONS_LAYER MBO
  #define MH_AUTO_BUTTONS_TIMEOUT 5000
#endif