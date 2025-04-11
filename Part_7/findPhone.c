#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //fork(), pipe(), dup2(), execlp(), close()
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        exit(1);
    }

    char *name = argv[1];

    int pipe1[2]; //cat to grep
    int pipe2[2]; //grep to cut

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }
    //first child process(cat)
    pid_t pid1 = fork();
    if (pid1 == 0) {
        //redirect cat output to pipe
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        //replace process with cat
        execlp("cat", "cat", "phones.txt", NULL);
        perror("cat failed");
        exit(1);
    }
    //second child(grep)
    pid_t pid2 = fork();
    if (pid2 == 0) {
        //redirect stdin from pipe1
        dup2(pipe1[0], STDIN_FILENO);
        //redirect stdout to pipe2
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", name, NULL);
        perror("grep failed");
        exit(1);
    }
    //third child process(cut)
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
    //wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
