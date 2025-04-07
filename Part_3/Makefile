CC = gcc
CFLAGS = -Wall -fPIC -g
LDFLAGS = -shared
TARGET_LIB = libmandelbrot.so
TARGET_BIN = mandelbrot_program

all: $(TARGET_LIB) $(TARGET_BIN)

$(TARGET_LIB): mandelbrot.o
	$(CC) $(LDFLAGS) -o $@ $^

mandelbrot.o: mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -c mandelbrot.c

$(TARGET_BIN): main.c mandelbrot.h
	$(CC) $(CFLAGS) -o $@ main.c -L. -lmandelbrot -lm

clean:
	rm -f *.o $(TARGET_BIN) $(TARGET_LIB)
