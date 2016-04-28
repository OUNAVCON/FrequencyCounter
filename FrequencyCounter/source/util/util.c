#include "util.h"
#include "stdlib.h"

/*
 * @param value the value to convert
 * @param array is a pointer to the first element in the array
 * @param arrayLength the size of the array (starting at 1)
 * @param startDigit the first digit to start with. assume index is starts at 0 at decimal point.
 */
void convertFloatToIntArray(float value, int array[], int arrayLength, int startDigit){

		int n = (int) value;
		int arrayIndex = 0;

		for(int index = 0; index < arrayLength; index++){
			array[index] = 0;
		}

		/* count number of digits */
		int numberOfDigits = 0; /* digit position */

		while (n != 0)
		{
		    n /= 10;
		    numberOfDigits++;
		}

		//int numberArray[numberOfDigits];

		int index = 0; //
		n = (int) value;

		/* extract each digit */
		while (n != 0)
		{
			if(index >= startDigit){
				array[arrayIndex] = n % 10;
				arrayIndex++;
			}
			if(index >= arrayLength){
				break;
			}
		    n /= 10;
		    index++;
		}
}
