#ifndef GATE_TIMER_H
#define GATE_TIMER_H

#include "fsl_pit.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define gateTimerISR PIT0_IRQHandler
#define PIT_IRQ_ID PIT0_IRQn
/* Get source clock for PIT driver */
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_CoreSysClk)

#define NUMBER_OF_SAMPLES_TO_AVG 10
#define NUMBER_OF_SAMPLES_BETWEEN_UPDATES 10

/*
 * Enable the gate timer for the counter.
 * @param gateTime the time in us that the gate should exist for.
 */
void enableGateTimer(unsigned int gateTime);

void gateTimerISR();


/*
 * number of bits	16
 * min count	1
 * max count	65536
 *
 * GateTime(ms)	  100			50			10			5			1
 * Min Frequency	10.00E+00	20.00E+00	100.00E+00	200.00E+00	1.00E+03
 * Max Frequency	655.36E+03	1.31E+06	6.55E+06	13.11E+06	65.54E+06
 */
#endif
