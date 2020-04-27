# KK_ansi60
60% mechanical keyboard

KK_ansi60 keyboard is inspired by [GH60 open source keybord](https://github.com/komar007/gh60).
Case and mounting plate are made from one piece of aluminium alloy. This feature allows very
solid and compact design. On the other hand only ane switch layout is supported.
Keyboard support TMK firmware, so everything is open source and customizable. On default there
are two base layers. Active layer is indicated with LED under FN1 or FN2 key.

![title image](https://github.com/MarekKap/KK_ansi60/blob/master/Other/title_image.png)

## Build instructions
1. Solder all SMDs parts on PCB.
2. Temporary solder USB cable on connector `J1`.
3. Load firmware.
   1. Plug USB cable into computer.
   2. Run command `dmesg`, you should see `Product: ATm32U4DFU` in output list. If not,
      double check your soldering and check if you have ATMEGA32u4 with DFU bootloader.
   3. Clone repo `git clone "https://github.com/MarekKap/KK_ansi60"`.
   4. Go to firmware directory `cd KK_ansi60/Firmware/`.
   5. Compile program `make`.
   6. Load firmware into keyboard `sudo make dfu`.
   7. Unplug USB cable from computer.
4. Desolder USB cable.
5. Install keycaps stabilizers on top plate.
6. Install some switchies on on top plate. Start with edges and long keys.
7. Flip the top plate and put PCB on installed switches.
8. Cut switch legs. Keep in mind, there is only 2mm space between PCB and bottom plate.
9. Solder switches on PCB.
10. Install, cut and solder rest of the switches.
11. Install, cut and solder `LED1` and `LED2`.
12. Remove insulation from USB cable. Use heat shring tube or your nylon cable sleeve will
    start stripping over time.
13. Use cable tie to hold USB cable in place.
14. Solder free USB wires to connector `J1`. Keep `D+` and `D-` wires twisted as long as
    possible.
15. Hold down USB wires using kapton tape on PCB.
16. Install CNC legs with screws on bottom plate and put self adhesive pads in place.
17. Stick a insulation sticker on bottom plate (PCB side).
18. Screw bootom and top piece together with M2.5 screws.
19. Plug USB cable into computer and enjoy your keyboard. :-)

