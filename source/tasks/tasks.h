#ifndef TASKS_H
#define TASKS_H

#include "FreeRTOS.h"
#include "timers.h"

/* Define the data type that will be queued. */
typedef struct Frequncy_t
{
char ucMessageID;
float frequency;
} Frequency_t;


/* Define the queue parameters. */
#define FREQUNCY_QUEUE_LENGTH 5
#define FREQUNCY_QUEUE_ITEM_SIZE sizeof( Frequency_t )


/* Task priorities. */
#define heartbeat_task_PRIORITY (configMAX_PRIORITIES - 1)


/* task functions */
void heartbeat_Task(void *pvParameters);

/* callback for timer to update display */
void updateDisplayCallback( xTimerHandle pxTimer );

#endif
