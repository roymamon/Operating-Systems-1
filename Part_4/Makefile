CC = gcc
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
TARGET = dijkstra

all: $(TARGET)

$(TARGET): dijkstra.c
	$(CC) $(CFLAGS) -o $(TARGET) dijkstra.c

gcov:
	gcov dijkstra.c

clean:
	rm -f $(TARGET) *.gcno *.gcda *.gcov
