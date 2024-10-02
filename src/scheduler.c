#include "scheduler.h"
#include <stdio.h>

/**
 * @brief Initializes the scheduler by setting the initial values for task management.
 *
 * @param scheduler Pointer to the Scheduler struct that will be initialized.
 * 
 * This function sets the current task index to 0 and the task count to 0,
 * preparing the scheduler to add and manage tasks.
 */
void init_scheduler(Scheduler *scheduler) {
    scheduler->current_task = 0;
    scheduler->task_count = 0;
}

/**
 * @brief Adds a new task to the scheduler.
 *
 * @param scheduler Pointer to the Scheduler struct managing tasks.
 * @param func Function pointer to the task function that will be added to the scheduler.
 *
 * This function creates a new Task, assigns it a function to run, and sets its state
 * to TASK_READY. It increments the task count in the scheduler to keep track of how 
 * many tasks have been added.
 */
void add_task(Scheduler *scheduler, void (*func)(void)) {
    if (scheduler->task_count < MAX_TASKS) {
        create_task(&scheduler->tasks[scheduler->task_count], func);
        scheduler->task_count++;
    }
}


/**
 * @brief Runs all tasks in the scheduler in a loop until all tasks are completed.
 *
 * @param scheduler Pointer to the Scheduler struct that holds and manages tasks.
 *
 * This function iterates through the tasks added to the scheduler and executes them
 * one by one. It checks the state of each task:
 * - If a task is in TASK_READY state, it runs the task.
 * - After running, it marks the task as TASK_DONE.
 */
void run_scheduler(Scheduler *scheduler) {
    while (1) {
        Task *current = &scheduler->tasks[scheduler->current_task];

        // If the task is waiting for I/O, skip it for now
        if (current->state == TASK_WAITING_FOR_IO) {
            scheduler->current_task = (scheduler->current_task + 1) % scheduler->task_count;
            continue;
        }

        // If the task is done, move to the next task
        if (current->state == TASK_DONE) {
            scheduler->current_task = (scheduler->current_task + 1) % scheduler->task_count;
            continue;
        }

        // Run the task
        current->state = TASK_RUNNING;
        current->function(); // Task does its work
        if (current->is_waiting_for_io == 0) {
            current->state = TASK_DONE;
        }

        // Move to the next task
        scheduler->current_task = (scheduler->current_task + 1) % scheduler->task_count;

        // Check if all tasks are done
        int all_done = 1;
        for (int i = 0; i < scheduler->task_count; i++) {
            if (scheduler->tasks[i].state != TASK_DONE) {
                all_done = 0;
                break;
            }
        }
        if (all_done) break;
    }
}