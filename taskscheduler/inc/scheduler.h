#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <setjmp.h>  // Required for setjmp() and longjmp()

#define MAX_TASKS 3  // Maximum number of tasks

// Task structure
typedef struct {
    jmp_buf context;  // Task context (for setjmp/longjmp)
    int task_id;      // Task ID
    int active;       // Whether the task is active or finished
} Task;

// Function prototypes
void init_scheduler(void);
void create_task(void (*task_func)(void), int task_id);
void scheduler_run(void);
void yield(void);

// Scheduler functions for each task
void task1(void);
void task2(void);
void task3(void);

#endif // SCHEDULER_H
