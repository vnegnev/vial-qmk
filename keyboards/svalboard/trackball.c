#include "quantum.h"
#include "pointing_device.h"
#include "keyboard.h"

void keyboard_post_init_kb(void) {
    pointing_device_set_cpi_on_side(true, 5000);  // Right.
    pointing_device_set_cpi_on_side(false, 5000); // Left.
    keyboard_post_init_user();
}