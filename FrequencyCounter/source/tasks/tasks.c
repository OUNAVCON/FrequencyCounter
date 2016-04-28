/* KDS includes */

#include "board.h"
#include "pin_mux.h"
#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"

/* App specific includes */
#include "hardware/hardware.h"
#include "../main.h"
#include "tasks.h"
#include "util/util.h"

static int digitArray[NUMBER_OF_DIGITS];
static int digitIndex = 0;
static int startDigit = 1; //Start at digit 1 (tens)

/*!
 * @brief Task responsible for blinking the LED as a heartbeat.
 */
void heartbeat_Task(void *pvParameters) {

	const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

	for(;;){
		//LED_BLUE_TOGGLE();
		//PRINTF("Hello world. %d\r\n", i);
		LED_BLUE_TOGGLE();
		vTaskDelay(xDelay);
		}
}

/* Define a callback function that will be used by multiple timer instances. The callback
function does nothing but count the number of times the associated timer expires, and stop the
timer once the timer has expired 10 times. */
void updateDisplayCallback(xTimerHandle pxTimer){
 /* init task here */

	unsigned portBASE_TYPE uxNumberOfItems;
	Frequency_t frequency;

		/* do the work here. */


//	float average = 0;
//
//	if(sampleIndex >= NUMBER_OF_SAMPLES_TO_AVG){
//		sampleIndex = 0;
//	}else{
//		sampleIndex++;
//	}
//
//	frequencySamples[sampleIndex] = rand() * 5000.0;
//
//	for(int index = 0; index < NUMBER_OF_SAMPLES_TO_AVG; index++){
//		average+=frequencySamples[index];
//	}
//	average /= (float) NUMBER_OF_SAMPLES_TO_AVG;
//
//	if(updateIndex >= NUMBER_OF_SAMPLES_BETWEEN_UPDATES){
//		 //send update
//		ISRfrequency.frequency = average;
//		updateIndex = 0;
//	 }else{
//		updateIndex++;
//	 }

		convertFloatToIntArray(1234567.89f, digitArray, NUMBER_OF_DIGITS, startDigit);

		/*get the current value from the counter, this is in a queue.
		 * convert it to an array of digits.
		 * update
		 * 1. turn off all 7-segments
		 * 2. set read the value in the array
		 * 2. set output based on array
		 */
		blankDigits();
		writeDigit(digitArray[digitIndex]);
		selectDigit(digitArray[digitIndex]);
		//update index
		digitIndex++;
		if(digitIndex >= NUMBER_OF_DIGITS){
			digitIndex = 0;
		}
}
