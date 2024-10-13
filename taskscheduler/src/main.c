#include <stdio.h>
#include "scheduler.h"
#include "tasks.h"
#include "utils.h"

/*
**  Main entry point of the program, initializes the scheduler and creates tasks.
*/
int main(int argc, char *argv[]) {
    parse_args(argc, argv);  // Parse command-line arguments for task configuration
    
    init_scheduler();  // Initialize the task scheduler
    
    // Create tasks for each sensor
    create_task(task1, 0);  // Temperature sensor
    create_task(task2, 1);  // Humidity sensor
    create_task(task3, 2);  // Pressure sensor
    
    // Run the scheduler
    scheduler_run();
    
    return 0;
}
