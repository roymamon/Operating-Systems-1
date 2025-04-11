CC = gcc
CFLAGS = -Wall -g

TARGETS = add2PB findPhone

all: $(TARGETS)

add2PB: add2PB.c
	$(CC) $(CFLAGS) -o add2PB add2PB.c

findPhone: findPhone.c
	$(CC) $(CFLAGS) -o findPhone findPhone.c

clean:
	rm -f $(TARGETS)