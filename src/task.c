#include "task.h"
#include <stdio.h>
#include <string.h>

/*
**  @brief Initializes a new task by assigning it a function and setting its state to TASK_READY.
**
**  @param task Pointer to the Task struct that will be initialized.
**  @param func Function pointer to the task's function that will be executed when the task runs.
**
**  This function sets up the Task struct by assigning the provided function to it,
**  initializing the task's state to TASK_READY, and clearing the task's stack space.
**  It prepares the task to be managed and executed by the scheduler.
*/
void create_task(Task *task, void (*func)(void)) {
    task->function = func;
    task->state = TASK_READY;
    task->is_waiting_for_io = 0; // Task is not waiting for I/O initially
    memset(task->stack, 0, TASK_STACK_SIZE); // Clear task stack
}

/*
** @brief Initializes a new I/O task by assigning it a function and setting its state to TASK_READY, with the task flagged as waiting for I/O.
**
** @param task Pointer to the Task struct that will be initialized.
** @param func Function pointer to the task's function that will be executed when the task runs.
**
** This function sets up the Task struct by assigning the provided function to it,
** initializing the task's state to TASK_READY, and automatically setting the is_waiting_for_io flag
** to indicate that the task will be waiting for I/O operations.
*/
void create_io_task(Task *task, void (*func)(void)) {
    task->function = func;
    task->state = TASK_READY;
    task->is_waiting_for_io = 1;  // Task will be waiting for I/O
    memset(task->stack, 0, TASK_STACK_SIZE); // Clear task stack
}



/*
**  @brief Switches the context from the current task to the next task.
**
**  @param current Pointer to the current Task that is currently running and whose context will be saved.
**  @param next Pointer to the next Task whose context will be restored to start execution.
**
**  This function saves the current task's context using setjmp and then switches to the next task's context using longjmp.
**  If the task has already been switched to, the setjmp returns 1 and resumes execution from that task's point.
*/
void switch_task(Task *current, Task *next) {
    if (setjmp(current->context) == 0) {
        longjmp(next->context, 1); // Switch to the next task
    }
}

