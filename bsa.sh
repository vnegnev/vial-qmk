#!/usr/bin/env sh
env CFLAGS+="-D PS2_MOUSE_ROTATE=90" make svalboard/trackpoint/right:vial:svalboard_trackpoint_right_90.uf2
env CFLAGS+="-D PS2_MOUSE_ROTATE=90" make svalboard/trackpoint/left:vial:svalboard_trackpoint_left_90.uf2
env CFLAGS+="-D PS2_MOUSE_ROTATE=270" make svalboard/trackpoint/right:vial:svalboard_trackpoint_right_270.uf2
env CFLAGS+="-D PS2_MOUSE_ROTATE=270" make svalboard/trackpoint/left:vial:svalboard_trackpoint_left_270.uf2
make svalboard/left:vial
make svalboard/right:vial
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES PS2_MOUSE_ROTATE=90" make svalboard/trackpoint/right:vial:svalboard_trackpoint_right_90_dark.uf2
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES PS2_MOUSE_ROTATE=90" make svalboard/trackpoint/left:vial:svalboard_trackpoint_left_90_dark.uf2
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES PS2_MOUSE_ROTATE=270" make svalboard/trackpoint/right:vial:svalboard_trackpoint_right_270_dark.uf2
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES PS2_MOUSE_ROTATE=270" make svalboard/trackpoint/left:vial:svalboard_trackpoint_left_270_dark.uf2
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES make svalboard/left:vial:svalboard_left_dark.uf2
env CFLAGS+="-D THUMB_DOWN_ACTIVE_DARK=YES make svalboard/right:vial:svalboard_right_dark.uf2
make svalboard/trackball/left:vial
make svalboard/trackball/right:vial
make svalboard/mouse/left:vial
make svalboard/mouse/right:vial
