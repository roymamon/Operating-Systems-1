CC = gcc
CFLAGS = -Wall -g

TARGETS = stack_overflow divide_by_zero invalid_memory

all: $(TARGETS)

stack_overflow: stack_overflow.c
	$(CC) $(CFLAGS) -o $@ $<

divide_by_zero: divide_by_zero.c
	$(CC) $(CFLAGS) -o $@ $<

invalid_memory: invalid_memory.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) core* *.o
