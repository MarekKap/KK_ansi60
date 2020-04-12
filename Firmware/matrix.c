/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

static void init_cols(void) {
  // Must disable JTAG to use PORTF pins as GPIO
  MCUCR = (1<<JTD);
  MCUCR = (1<<JTD);
  // Input with pull-up(DDR:0, PORT:1)
  DDRF  &= ~(1<<PF7 | 1<<PF6 | 1<<PF5 | 1<<PF4 | 1<<PF1 | 1<<PF0);
  PORTF |=  (1<<PF7 | 1<<PF6 | 1<<PF5 | 1<<PF4 | 1<<PF1 | 1<<PF0);
  DDRE  &= ~(1<<PE6);
  PORTE |=  (1<<PE6);
  DDRD  &= ~(1<<PD7 | 1<<PD6 | 1<<PD4);
  PORTD |=  (1<<PD7 | 1<<PD6 | 1<<PD4);
  DDRC  &= ~(1<<PC7 | 1<<PC6);
  PORTC |=  (1<<PC7 | 1<<PC6);
  DDRB  &= ~(1<<PB7 | 1<<PB4);
  PORTB |=  (1<<PB7 | 1<<PB4);
}

static matrix_row_t read_cols(void) {
  return
    (PINF&(1<<PF7) ? 0 : (1<<0)) |
    (PINF&(1<<PF6) ? 0 : (1<<1)) |
    (PINF&(1<<PF5) ? 0 : (1<<2)) |
    (PINF&(1<<PF4) ? 0 : (1<<3)) |
    (PINF&(1<<PF1) ? 0 : (1<<4)) |
    (PINF&(1<<PF0) ? 0 : (1<<5)) |
    (PINE&(1<<PE6) ? 0 : (1<<6)) |
    (PINB&(1<<PB7) ? 0 : (1<<7)) |
    (PIND&(1<<PD4) ? 0 : (1<<8)) |
    (PIND&(1<<PD6) ? 0 : (1<<9)) |
    (PIND&(1<<PD7) ? 0 : (1<<10)) |
    (PINB&(1<<PB4) ? 0 : (1<<11)) |
    (PINC&(1<<PC6) ? 0 : (1<<12)) |
    (PINC&(1<<PC7) ? 0 : (1<<13));
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: D3  D2  D1  D0  D5
 */
static void select_row(uint8_t row) {
  // Output low(DDR:1, PORT:0) to select
  switch (row) {
    case 0:
      DDRD  |= (1<<PD3);
      PORTD &= ~(1<<PD3);
      break;
    case 1:
      DDRD  |= (1<<PD2);
      PORTD &= ~(1<<PD2);
      break;
    case 2:
      DDRD  |= (1<<PD1);
      PORTD &= ~(1<<PD1);
      break;
    case 3:
      DDRD  |= (1<<PD0);
      PORTD &= ~(1<<PD0);
      break;
    case 4:
      DDRD  |= (1<<PD5);
      PORTD &= ~(1<<PD5);
      break;
  }
}

static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRD  &= ~0b00101111;
    PORTD &= ~0b00101111;
}