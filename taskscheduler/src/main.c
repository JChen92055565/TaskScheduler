#include <stdio.h>
#include "scheduler.h"

/*
**  Main entry point of the program, initializes the scheduler and creates tasks.
*/
int main() {
    init_scheduler();  // Initialize the task scheduler
    
    // Create tasks
    create_task(task1, 0);
    create_task(task2, 1);
    create_task(task3, 2);
    
    // Run the scheduler
    scheduler_run();
    
    return 0;
}
