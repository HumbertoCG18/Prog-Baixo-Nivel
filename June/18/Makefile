CFLAGS = -Wall -g
CC = gcc
LD = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CLEAN_FILES = main $(OBJS)

.PHONY: all
all: main

main: $(OBJS)
	$(LD) $(OBJS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(CLEAN_FILES)
