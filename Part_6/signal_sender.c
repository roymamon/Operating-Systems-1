#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void send_bit(pid_t pid, int bit) {
    int sig = bit ? SIGUSR2 : SIGUSR1;
    kill(pid, sig);
    usleep(50000); // small delay to prevent signal loss
}

int main() {
    pid_t pid;
    int number;

    printf("Enter receiver PID: ");
    scanf("%d", &pid);
    printf("Enter message (0-255): ");
    scanf("%d", &number);

    if (number < 0 || number > 255) {
        fprintf(stderr, "Invalid number. Must be between 0 and 255.\n");
        return 1;
    }

    for (int i = 7; i >= 0; i--) {
        int bit = (number >> i) & 1;
        send_bit(pid, bit);
    }

    return 0;
}