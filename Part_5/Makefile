CC = gcc
CFLAGS = -Wall -g -pg
TARGET = max_subarray

all: $(TARGET)

$(TARGET): max_subarray.c
	$(CC) $(CFLAGS) -o $(TARGET) max_subarray.c

run:
	./$(TARGET) 42 10000

gprof: run
	gprof $(TARGET) gmon.out > analysis.txt

clean:
	rm -f $(TARGET) gmon.out analysis.txt
