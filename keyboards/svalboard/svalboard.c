#include "svalboard.h"

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

#ifdef PS2_MOUSE_ENABLE
void ps2_mouse_init_user() {
  //sensitivity command in fourth byte 00 = 0 multiplier, FF = 2.0 multiplier
  /*
    PS2_MOUSE_SEND(0xE2);
    PS2_MOUSE_SEND(0x81);
    PS2_MOUSE_SEND(0x4A);
    PS2_MOUSE_SEND(0x59);
    */

//Z tap -- doesn't seem to work.  0x01 is on.

  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
  PS2_MOUSE_SEND(0x47, "pts: 0x47");
  PS2_MOUSE_SEND(0x2C, "pts: 0x2C");
  PS2_MOUSE_SEND(0x00, "pts: 0x00");  // 01 turns on Z tap, 00 turns off


/*
E2 80 63
E2 81 63 XX
Drift Threshold [drift]
This parameter is used to set the threshold at which drift calibration will occur. Low drift
thresholds should be used to maximize the effectiveness of the drift calibration algorithms.
If the difference between the smoothed conversion value and the trial value remains within
the internal drift threshold, drift calibration will occur. The format of this parameter is
x"FF"- drift threshold. The default value for drift is x"FE", corresponding to a drift
threshold of 1. A reset (x"FF") or set default (x"F6") command will not affect this byte.

*/
  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
  PS2_MOUSE_SEND(0x81, "pts: 0x81");
  PS2_MOUSE_SEND(0x63, "pts: 0x63");
  PS2_MOUSE_SEND(0x80, "pts: 0xFE");  // 0xFE is default threshold of 1  try low and see what happens

/*
E2 80 64
E2 81 64 XX
XY running average drift time constant [xydriftavg]
This parameter sets the time constant used for the X and Y axis running average routines
used in conjunction with a high sensitivity TrackPoint circuit for drift control only. This
directly affects the performance of the drift cancellation algorithms. The least possible
averaging which allows calibration to take place should be used, otherwise improper
calibrations will occur during slow cursor movement. The formula used for running
average is: A = A + (N - A) X where A = running average, N = present sample (lowx or
256
lowy, low order l counts), and X is xydriftavg. The default value for xydriftavg will
depend upon the presence of a jumper between pins 26 and 21 of the TPM754. If the
jumper is present (noisier sensor), the default value will be x"40" (decimal 64)
corresponding to approximately a 4 sample average, otherwise the default value is x"80"
(decimal 128) corresponding to a 2 sample average. This value is not affected by a reset
(x"FF") or set default (x"F6") command
*/
  PS2_MOUSE_SEND(0xE2, "pts: 0xE2");
  PS2_MOUSE_SEND(0x81, "pts: 0x81");
  PS2_MOUSE_SEND(0x63, "pts: 0x64");
  PS2_MOUSE_SEND(0x80, "pts: 0xFE");  // 0xFE is default threshold of 1  try low and see what happens

  // transfer function plateau speed -- default is 0x61
/*
  PS2_MOUSE_SEND(0xE2, "tfups: 0xE2");
  PS2_MOUSE_SEND(0x80, "tfups: 0x80");
  PS2_MOUSE_SEND(0x60, "tfups: 0x60");
  PS2_MOUSE_SEND(0xf0, "tfups: 0xf0");
  */
}
#endif

