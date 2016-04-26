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

#endif
