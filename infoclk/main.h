/*
 *  InfoClock - ESP8266 based informeter/wall-clock
 *  ESP8266 contoller uses Max72xx modules as a display
 *  Internal/external sensors/message brokers could be used as an information source
 *
 *  Author		: Emil Muratov
 *
 *  This file        : main.h
 *  This file Author : Emil Muratow
 *
 *  Description      : Common includes and defines required by whole project
 *  (c) Emil Muratov 2017
 *
 */

#pragma once
// Sketch configuration
#include "globals.h"    // EmbUI macro's for LOG
#include "config.h"
#include "uistrings.h"  // non-localized text-strings
#include "ui_i18n.h"    // localized GUI text-strings


#define UPD_RESTART_DELAY   5   // restart delay when updating firmware
#define BAUD_RATE	115200	// serial debug port baud rate

// PROGMEM strings
// sprintf template for json version data
static const char PGverjson[] PROGMEM = "{\"ChipID\":\"%x\",\"FlashSize\":%u,\"Core\":\"%s\",\"SDK\":\"%s\",\"firmware\":\"%s\",\"version\":\"%s\",\"CPUMHz\":%u,\"Heap\":%u,\"Uptime\":%u,}";

// Task Scheduler lib	https://github.com/arkhipenko/TaskScheduler
#define _TASK_SLEEP_ON_IDLE_RUN
#define _TASK_STD_FUNCTION   // Compile with support for std::function 
#define _TASK_SCHEDULING_OPTIONS
#include <TaskSchedulerDeclarations.h>

// TaskScheduler
//Let the runner object be a global, single instance shared between object files.
extern Scheduler ts;

void create_parameters();       // декларируем для переопределения weak метода из фреймворка для WebUI

// reboot esp with a delay
void espreboot(void);

// WiFi connection callback
void onSTAGotIP();
// Manage network disconnection
void onSTADisconnected();

