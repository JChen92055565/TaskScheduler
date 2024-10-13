#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <setjmp.h>

#define MAX_TASKS 3  // Maximum number of tasks

// Task structure
typedef struct {
    jmp_buf context;  // Task context (for setjmp/longjmp)
    int task_id;      // Task ID
    int active;       // Whether the task is active or finished
} Task;

// Global task array declared as extern for use in other files
extern Task tasks[MAX_TASKS];

// Function prototypes
void init_scheduler(void);
void create_task(void (*task_func)(void), int task_id);
void scheduler_run(void);
void yield(void);

#endif // SCHEDULER_H
