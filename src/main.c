#include "scheduler.h"
#include <stdio.h>

Scheduler scheduler; // Declare the scheduler globally so it's accessible within tasks

void task1() {
    printf("Task 1 is running!\n");
}

void task2() {
    Task *current_task = &scheduler.tasks[scheduler.current_task]; // Get current task

    printf("Task 2 is waiting for input. Please type something: ");
    
    char input[100];
    fgets(input, sizeof(input), stdin);  // Task waits for input

    // Once input is received, reset the waiting flag and mark as done
    current_task->is_waiting_for_io = 0;
    current_task->state = TASK_DONE;

    printf("Task 2 received input: %s", input);
}

void task3() {
    printf("Task 3 is running!\n");
}

int main() {
    init_scheduler(&scheduler);

    add_task(&scheduler, task1);
    create_io_task(&scheduler.tasks[scheduler.task_count], task2); // Use create_io_task for I/O-bound task
    scheduler.task_count++;  // Manually increment the task count since we're directly modifying the task array
    add_task(&scheduler, task3);

    run_scheduler(&scheduler);

    printf("All tasks are done!\n");
    return 0;
}
