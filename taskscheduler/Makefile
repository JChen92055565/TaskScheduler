# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I./inc -Wall

# Source and output directories
SRC_DIR = src
BUILD_DIR = build

# Output executable name
TARGET = $(BUILD_DIR)/scheduler_program

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/scheduler.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
