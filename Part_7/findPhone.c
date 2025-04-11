#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        exit(1);
    }

    char *name = argv[1];

    int pipe1[2]; 
    int pipe2[2]; 

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("cat", "cat", "phones.txt", NULL);
        perror("cat failed");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", name, NULL);
        perror("grep failed");
        exit(1);
    }

    pid_t pid3 = fork();
    if (pid3 == 0) {
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("cut", "cut", "-d,", "-f2", NULL);
        perror("cut failed");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
