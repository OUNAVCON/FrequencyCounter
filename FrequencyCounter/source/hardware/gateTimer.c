#include "gateTimer.h"

#include "board.h"
#include "fsl_pit.h"
#include "clock_config.h"
#include "fsl_ftm.h"

#include "../tasks/tasks.h"
#include "../main.h"

static float  frequencySamples[NUMBER_OF_SAMPLES_TO_AVG];
static unsigned int sampleIndex = 0;
static unsigned int updateIndex = 0;
static Frequency_t ISRfrequency;

void enableGateTimer(unsigned int gateTime){
	  /* Structure of initialize PIT */
	    pit_config_t pitConfig;

	    /*
	     * pitConfig.enableRunInDebug = false;
	     */
	    PIT_GetDefaultConfig(&pitConfig);

	    /* Init pit module */
	    PIT_Init(PIT, &pitConfig);

	    /* Set timer period for channel 0 */
	    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(gateTime, PIT_SOURCE_CLOCK));

	    /* Enable timer interrupts for channel 0 */
	    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

	    /* Enable at the NVIC */
	    EnableIRQ(PIT_IRQ_ID);

//	    clearCounter

	    PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void gateTimerISR(){
	/*
	 * stop comparator from counting.
	 * Read current count value.
	 */

	 PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, PIT_TFLG_TIF_MASK);
	 PIT_StopTimer(PIT,kPIT_Chnl_0);


	 /*
	  * Zero out comparator.
	  * Enable comparator.
	  */
}
