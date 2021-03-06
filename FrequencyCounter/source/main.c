/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include <string.h>

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* user includes */
#include "tasks/tasks.h"
#include "hardware/gateTimer.h"
#include "main.h"

/*!
 * @brief Application entry point.
 */
int main(void) {
  /* Init board hardware. */
  BOARD_InitPins();
  BOARD_BootClockRUN();
  //BOARD_BootClockHSRUN();
  BOARD_InitDebugConsole();

  /*Initialize timers here */
  const TickType_t displayTimerPeriod = 10 / portTICK_PERIOD_MS; // Refresh every a digit at 100hz.
  displayTimer = xTimerCreate( "updateDisplay", displayTimerPeriod, pdTRUE, (void *)0, updateDisplayCallback);
  if( displayTimer == NULL )
  {
  /* The timer was not created. TODO:Error handler here. */
  }else{
  /* Start the timer. */
	  if( xTimerStart(displayTimer, 0) != pdPASS )
	  {/* The start command could not be sent to the queue */}
  }


  /* Initialize queues here. */
  frequencyReadingQueue = xQueueCreate(FREQUNCY_QUEUE_LENGTH, FREQUNCY_QUEUE_ITEM_SIZE);
  if(frequencyReadingQueue == NULL){
	  /* Queue could not be started. */
  }

  /* Create RTOS task */
  xTaskCreate(heartbeat_Task, "Hello_task", configMINIMAL_STACK_SIZE, NULL, heartbeat_task_PRIORITY, NULL);


  /* Start scheduler */
  vTaskStartScheduler();

  for(;;) { /* Infinite loop to avoid leaving the main function */
    __asm("NOP"); /* something to use as a breakpoint stop while looping */
  }
}



