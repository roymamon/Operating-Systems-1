CC = gcc
CFLAGS = -Wall -g

all: signal_sender signal_receiver

signal_sender: signal_sender.c
	$(CC) $(CFLAGS) -o signal_sender signal_sender.c

signal_receiver: signal_receiver.c
	$(CC) $(CFLAGS) -o signal_receiver signal_receiver.c

clean:
	rm -f signal_sender signal_receiver
