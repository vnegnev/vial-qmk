# Svalboard RP2040

![Svalboard](https://www.svalboard.com)

Svalboard - Datahand Forever!

Keyboard Maintainer: [morganvenable](https://github.com/morganvenable/) [@morganmoto](https://twitter.com/morganmoto)  
Hardware Supported: RP2040, Svalboard Alpha 
Hardware Availability: [Store](https://www.svalboard.com)

Svalboard supports Vial as its primary configuration tool due to incredible portability, no-flash live layout editing, and nice GUI.
You can also build vanilla QMK for more advanced stuff -- currently maintained in a separate repo not part of this organization.
Vial downloads and docs available at https://get.vial.today

## Bootloader
For units with MCU 1.0 or v2B, press reset twice in 500ms to enter bootloader.
For units with MCU 0.9, the reset button is miswired -- you need to hold BOOT while plugging in USB to enter bootloader mode, because early units have a schematic gaffe on the reset button.
There is a rework available, but it involves desoldering a resistor and running a wire -- not reccommended.

## Build steps
If building on windows, QMK MSYS will get the job done -- it builds dooooog slow, but if you just want a working toolchain it's the fastest path.
Build example for this keyboard (after setting up your build environment):
```
make svalboard:vial
```
You can then put the device in bootloader mode and copy the UF2 file from your vial-qmk root directory to the device's drive letter.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

