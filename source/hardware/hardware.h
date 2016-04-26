#ifndef HARDWARE_H
#define HARDWARE_H


#define NUMBER_OF_DIGITS 7


/*
 * Write the input parameter value to the
 * 7-segment display.
 */
void writeDigit(int value);

/*
 * Select which 7-segment display to
 * display
 */
void selectDigit(int value);

/*
 * Dissable all 7-segment displays
 */
void blankDigits();

/*
 * Enable all digits and write a write a value of 8.
 * This shows all digits and all segments lit.
 */
void testDigits();

#endif
