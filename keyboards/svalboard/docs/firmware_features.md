# Svalboard firmware features

This page describes the custom keycodes, layers and other functions of the Svalboard fork of vial-qmk.

*Note:* The firmware is rapidly changing and many features have not been thoroughly tested in combination with each other. If you see unexpected behavior, please open an issue on Github or post in the `svalboard` Discord.

## Quickstart
Once you have installed Vial and connected your Svalboard, you can open a list of user keybindings in the bottom panel:

![User keys](./user_keys.png)

Hover over each keybinding to see a brief description. To map it to a Svalboard key, select a layer (0 - 15), click a physical key, then click the keybinding.

## Automouse mode
If you move your pointing device the Svalboard will switch to Layer 15 by default. The indicator LEDs will turn magenta, and some of the keys act as mouse buttons.

You can exit this mode by hitting any key not mapped to a mouse button or pointing device feature.

*Note:* Many of the keybindings will not work on the automouse layer, due to the way the key events are processed. A keycode must be in the following set to not exit the automouse layer (as of commit c870b94221a23b8b835dbabefaa5956ae59ecb82):

```c
        switch (keycode) {
            case KC_BTN1:
            case KC_BTN2:
            case KC_BTN3:
            case KC_BTN4:
            case KC_BTN5:
            case KC_WH_U:
            case KC_WH_D:
            case KC_WH_R:
            case KC_WH_L:
            case KC_LSFT:
            case KC_RSFT:
            case KC_LCTL:
            case KC_RCTL:
            case KC_LALT:
            case KC_RALT:
            case KC_LGUI:
            case KC_RGUI:
            case SV_LEFT_SCROLL_TOGGLE:
            case SV_RIGHT_SCROLL_TOGGLE:
            case SV_LEFT_SCROLL_HOLD:
            case SV_RIGHT_SCROLL_HOLD:
            case SV_SNIPER_2:
            case SV_SNIPER_3:
            case SV_SNIPER_5:
            case SV_RECALIBRATE_POINTER:
                break;
```

This can easily be changed by modifying the `switch` statement visible above in `process_record_kb()` in [keymap_support.c](../keymaps/keymap_support.c). Ask on the Discord for more info.

### Auto-exit timer
[TODO]

### Trackpoint recalibration
If your mouse pointer begins to drift, try recalibrating the zero by hitting 'down' on one of the pinkies, which by default will activate `SV_RECALIBRATE_POINTER`.

### Activation threshold
[TODO]

## Sniper mode
[TODO]

## Scroll-mode lock and scroll-mode hold
The keycodes `SV_LEFT_SCROLL_TOGGLE` and `SV_RIGHT_SCROLL_TOGGLE` switch the left or right pointing device from moving the mouse pointer to acting as a scroll wheel. When these are activated/deactivated, the state is saved in the Svalboard EEPROM. Some users with dual pointing devices like to use one side to move the pointer, and one to exclusively scroll.

The keycodes `SV_LEFT_SCROLL_HOLD` and `SV_RIGHT_SCROLL_HOLD` swap the left or right pointing device to a scroll, which is only active while the key is held down. If the pointing device is already a scroll, the key will have no additional effect.

## Pointer DPI adjustment
[TODO]
