#include <stdio.h>
#include <setjmp.h>
#include "scheduler.h"

/* ** Global task array, no need for 'static' since it's now shared across files ** */
Task tasks[MAX_TASKS];
static int current_task = -1;  // The current task ID
static int total_tasks = 0;    // Total number of tasks

/*
**  Initializes the task scheduler by resetting all tasks and marking them as inactive.
*/
void init_scheduler(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].task_id = i;
        tasks[i].active = 0;  // Initially inactive
    }
}

/*
**  Creates a new task and stores it in the task array. Activates the task for scheduling.
*/
void create_task(void (*task_func)(void), int task_id) {
    if (total_tasks < MAX_TASKS) {
        total_tasks++;
        tasks[task_id].active = 1;  // Activate the task
        if (setjmp(tasks[task_id].context) == 0) {
            printf("Debug: Running task %d\n", task_id + 1);
            task_func();  // Run the task function
        }
    } else {
        printf("Maximum task limit reached.\n");
    }
}

/*
**  Runs the task scheduler, switching between tasks until all are completed.
*/
void scheduler_run(void) {
    while (1) {
        int active_tasks = 0;  // Count active tasks
        
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].active) {
                active_tasks++;
                current_task = i;
                if (setjmp(tasks[i].context) == 0) {
                    printf("Switching to task %d\n", i + 1);
                    longjmp(tasks[i].context, 1);  // Switch to task
                }
            }
        }
        
        if (active_tasks == 0) {
            printf("All tasks completed. Exiting scheduler.\n");
            break;
        }
    }
}

/*
**  Yields control of the current task to the next task in the scheduler.
*/
void yield(void) {
    if (current_task >= 0) {
        if (setjmp(tasks[current_task].context) == 0) {
            printf("Yielding task %d\n", current_task + 1);
            longjmp(tasks[(current_task + 1) % MAX_TASKS].context, 1);  // Switch to the next task
        }
    }
}
