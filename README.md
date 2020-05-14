# KK_ansi60
60% mechanical keyboard

KK_ansi60 keyboard is inspired by [GH60 open source keyboard](https://github.com/komar007/gh60).
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

## Where to buy
| Item                        | Seller           | Price [EUR] | Note                |
| --------------------------- | ---------------- | ----------- | ------------------- |
| Resistor 22R (R1, R2)       | [Farnell][1]     |        0.09 | for 10 pcs          |
| Resistor 10K (R3, R4)       | [Farnell][2]     |        0.09 | for 10 pcs          |
| Resistor 82R (R5, R6)       | [Farnell][3]     |        0.13 | for 10 pcs          |
| Capacitor 10uF (C1)         | [Farnell][4]     |        0.80 | for 5 pcs           |
| Capacitor 0.1uF (C2-C6, C8) | [Farnell][5]     |        0.52 | for 10 pcs          |
| Capacitor 1uF (C7)          | [Farnell][6]     |        1.33 | for 5 pcs           |
| Capacitor 22pF (C9, C10)    | [Farnell][7]     |        1.23 | for 10 pcs          |
| White LED (LED1, LED2)      | [Farnell][8]     |        2.54 | for 5 pcs           |
| Quartz 16MHz (Y1)           | [Farnell][9]     |        0.84 |                     |
| ATMEGA32u4 (U1)             | [Farnell][10]    |        3.71 |                     |
| Diode TS148 (D1-D61)        | [Farnell][11]    |        5.23 |                     |
| Switch (S1-S61)             | [AliExpress][12] |       18.04 | 3 pin 65 pcs        |
| PCB                         | KK-electronic    |       25.00 | work in progress    |
| Stabilizers set             | [AliExpress][13] |        7.20 | 6.25u plate mounted |
| USB cable                   | Any local store  |        3.00 |                     |
| Top Plate                   | KK-electronic    |      120.00 | work in progress    |
| Bottom Plate                | KK-electronic    |       40.00 | work in progress    |
| CNC Legs                    | [AliExpress][15] |        3.00 | silver              |
| Self adhesive pads          | [AliExpress][16] |       11.00 | for 500 pcs         |
| Insulation sticker          | KK-electronic    |       10.00 | work in progress    |
| Keycap set                  | [AliExpress][17] |       21.00 |                     |

> If you are intrested in KK-electronic parts, please email at <kaplan.marek@gmail.com>.
> Price is approx. and can by significantly lower on group buy.

[1]: https://sk.farnell.com/multicomp/mcwr08x22r0ftl/res-22r-1-0-125w-0805-thick-film/dp/2447609
[2]: https://sk.farnell.com/multicomp/mcwr08x1002ftl/res-10k-1-0-125w-0805-thick-film/dp/2447553
[3]: https://sk.farnell.com/multicomp/mcmr08x820-jtl/res-82r-5-0-125w-0805-ceramic/dp/2073848
[4]: https://sk.farnell.com/kemet/c0805c106k8pactu/cap-10-f-10v-10-x5r-0805/dp/1463362 
[5]: https://sk.farnell.com/multicomp/mc0805b104m500ct/cap-0-1-f-50v-20-x7r-0805/dp/2627477
[6]: https://sk.farnell.com/multicomp/mc0805f105z500ct/cap-1-f-50v-y5v-0805/dp/1759432
[7]: https://sk.farnell.com/multicomp/mca0805c220jct/cap-22pf-100v-5-c0g-np0-0805/dp/9406247
[8]: https://sk.farnell.com/multicomp/mcl034swc-wh1/led-3mm-36-pure-white/dp/1581176
[9]: https://sk.farnell.com/qantek-technology-corporation/qc3216-0000f12b12m/crystal-16mhz-12pf-3-2mm-x-2-5mm/dp/2508646
[10]: https://sk.farnell.com/microchip/atmega32u4-au/mcu-8bit-megaavr-16mhz-tqfp-44/dp/1748525
[11]: https://sk.farnell.com/taiwan-semiconductor/ts4148-ryg/diode-small-signal-75v-0-15a-0805/dp/2708389
[12]: https://www.aliexpress.com/item/32797603005.html
[13]: https://www.aliexpress.com/item/32800781632.html
[15]: https://www.aliexpress.com/item/4000786300405.html
[16]: https://www.aliexpress.com/item/32242384655.html
[17]: https://www.aliexpress.com/item/32839583006.html

