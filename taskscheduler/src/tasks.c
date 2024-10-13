#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"
#include "scheduler.h"

/*
**  Task 1: Simulates a temperature sensor reading
*/
void task1(void) {
    for (int i = 0; i < 5; i++) {
        int temp = rand() % 40;  // Simulated temperature (0-39°C)
        printf("Task 1: Temperature Sensor, Reading %d: %d°C\n", i + 1, temp);
        yield();  // Yield control to the scheduler
    }
    tasks[0].active = 0;  // Mark task as finished
}

/*
**  Task 2: Simulates a humidity sensor reading
*/
void task2(void) {
    for (int i = 0; i < 5; i++) {
        int humidity = rand() % 100;  // Simulated humidity (0-99%)
        printf("Task 2: Humidity Sensor, Reading %d: %d%%\n", i + 1, humidity);
        yield();  // Yield control to the scheduler
    }
    tasks[1].active = 0;  // Mark task as finished
}

/*
**  Task 3: Simulates a pressure sensor reading
*/
void task3(void) {
    for (int i = 0; i < 5; i++) {
        int pressure = rand() % 1500 + 800;  // Simulated pressure (800-2299 hPa)
        printf("Task 3: Pressure Sensor, Reading %d: %d hPa\n", i + 1, pressure);
        yield();  // Yield control to the scheduler
    }
    tasks[2].active = 0;  // Mark task as finished
}
