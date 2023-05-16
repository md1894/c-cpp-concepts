# Specify the compiler
CC = gcc

# Specify the compiler flags
CFLAGS = -Wall -Werror

# Specify the target executable
TARGET = program

# Specify the source files
SRCS = tcp-client.c

# Specify the object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Target to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Target to compile individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)
