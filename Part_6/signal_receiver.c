#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

volatile sig_atomic_t current_bit = 0;
volatile sig_atomic_t received_number = 0;

void handle_bit(int sig) {
    received_number <<= 1;
    if (sig == SIGUSR2)
        received_number |= 1;
    current_bit++;

    if (current_bit == 8) {
        printf("Received %d\n", received_number);
        exit(0); 
    }
}

int main() {
    printf("My PID is %d\n", getpid());

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_bit;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}