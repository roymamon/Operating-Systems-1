#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//SIGUSR1 = 0, SIGUSR2 = 1
void send_bit(pid_t pid, int bit) {
    int sig;
    if (bit == 1)
    sig = SIGUSR2;
    else
    sig = SIGUSR1;
    //sends the chosen signal to the receiver
    kill(pid, sig);
    //control sending rate to avoid signal loss
    usleep(50000); 
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