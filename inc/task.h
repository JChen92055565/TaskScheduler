#ifndef TASK_H
#define TASK_H

#include <setjmp.h>

#define TASK_STACK_SIZE 1024

typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_DONE,
    TASK_WAITING_FOR_IO  // New state for tasks waiting for I/O
} TaskState;

typedef struct {
    jmp_buf context;
    void (*function)(void); // Task's function
    TaskState state;
    char stack[TASK_STACK_SIZE]; // Stack space for the task
    int is_waiting_for_io; // Flag indicating if the task is waiting for I/O
} Task;

// Task function prototypes
void create_task(Task *task, void (*func)(void));
void switch_task(Task *current, Task *next);
void create_io_task(Task *task, void (*func)(void));
#endif // TASK_H
