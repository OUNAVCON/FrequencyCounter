#ifndef MAIN_H
#define MAIN_H

#include "FreeRTOS.h"
#include "timers.h"
#include "queue.h"

xTimerHandle displayTimer;
xQueueHandle frequencyReadingQueue;

#endif
