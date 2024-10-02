/*
** Header file for scheduler struct
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

/*
**  Definitions
*/
#define MAX_TASKS 10

/*
**  Struct for Scheduler
*/
typedef struct {
    Task tasks[MAX_TASKS];
    int current_task;
    int task_count;
} Scheduler;

/*
**  Declare scheduler as an extern variable to be used across files
*/
extern Scheduler scheduler;

/*
**  Function Prototypes
*/
void init_scheduler(Scheduler *scheduler);
void add_task(Scheduler *scheduler, void (*func)(void));
void add_io_task(Scheduler *scheduler, void (*func)(void));
void run_scheduler(Scheduler *scheduler);

#endif
