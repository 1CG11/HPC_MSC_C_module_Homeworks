# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -O2

# Source files (make sure these files exist!)
SRCS = assignment4b.c sorting.c file_io.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = assignment4b

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile assignment4b.c
assignment4b.o: assignment4b.c sorting.h file_io.h
	$(CC) $(CFLAGS) -c assignment4b.c -o assignment4b.o

# Compile sorting.c
sorting.o: sorting.c sorting.h
	$(CC) $(CFLAGS) -c sorting.c -o sorting.o

# Compile file_io.c
file_io.o: file_io.c file_io.h
	$(CC) $(CFLAGS) -c file_io.c -o file_io.o

# Clean build files
clean:
		rm -f $(OBJS) $(TARGET)

