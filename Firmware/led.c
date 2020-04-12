/*
Copyright 2020 Marek Kaplan <kaplan.marek@gmail.com>

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

#include <avr/io.h>
#include "stdint.h"
#include "led.h"


void led_set(uint8_t usb_led)
{

}

void led1_on(void)
{
    DDRB |= (1<<PB5);
    PORTB &= ~(1<<PB5);
}

void led1_off(void)
{
    DDRB &= ~(1<<PB5);
}

void led2_on(void)
{
    DDRB |= (1<<PB6);
    PORTB &= ~(1<<PB6);
}

void led2_off(void)
{
    DDRB &= ~(1<<PB6);
}

