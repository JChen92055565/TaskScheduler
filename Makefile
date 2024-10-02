CC = gcc
CFLAGS = -Wall -g -Iinc   # Updated to use 'inc' instead of 'include'
LFLAGS = -lm

BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = inc

all: scheduler

scheduler: $(BUILD_DIR)/main.o $(BUILD_DIR)/scheduler.o $(BUILD_DIR)/task.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/scheduler $(BUILD_DIR)/main.o $(BUILD_DIR)/scheduler.o $(BUILD_DIR)/task.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/scheduler.h $(INCLUDE_DIR)/task.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/scheduler.o: $(SRC_DIR)/scheduler.c $(INCLUDE_DIR)/scheduler.h $(INCLUDE_DIR)/task.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/scheduler.c -o $(BUILD_DIR)/scheduler.o

$(BUILD_DIR)/task.o: $(SRC_DIR)/task.c $(INCLUDE_DIR)/task.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/task.c -o $(BUILD_DIR)/task.o

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/scheduler
