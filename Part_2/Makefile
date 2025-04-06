CC = gcc
CFLAGS = -Wall -g
TARGET = mandelbrot
SRC = mandelbrot.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

clean:
	rm -f $(TARGET) core* *.o
