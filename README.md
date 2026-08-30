# ATmega32 Interfacing Project 1

A drivers-based project on the AVR ATmega32 that reads a 4x4 keypad and controls
a 7-segment display, an LCD (16x2), and a buzzer.

Created by Mohammed — Aug 29, 2026

## What the project does

- Press any **digit (0-9)** -> it is shown on the 7-segment display.
- Press **/** -> the LCD clears and prints `MOHAMMED` (English).
- Press **\*** -> the LCD prints the Arabic name **محمد** using 4 custom
  characters (drawn manually, right-to-left).
- Every **10 key presses** the buzzer beeps for 200 ms.



The rule: **APP calls HAL, HAL calls MCAL, everyone uses LIB.**

## Wiring

| Device        | Pins                                   |
| ------------- | -------------------------------------- |
| Keypad        | PORTD (cols = pins 4-7, rows = pins 0-3) |
| 7-seg         | data to PORTC, common pin on PB4 (common cathode) |
| LCD           | data to PORTA (4-bit: pins 4-7), RS=PB0, RW=PB1, E=PB2 |
| Buzzer        | PB5                                    |

## Custom characters (Arabic name)

The LCD can store 8 user patterns in its CGRAM. The `*` key writes 3 patterns
(M, H, D) into CGRAM blocks 0-3 and displays them from COL9 to COL6 so the word
reads right-to-left as **محمد**.

