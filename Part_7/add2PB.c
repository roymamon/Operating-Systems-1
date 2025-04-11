#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024
#define PHONEBOOK_FILE "phones.txt"

int main() {
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    //read from standard input
    bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE);
    if (bytes_read <= 0) {
        write(STDERR_FILENO, "Failed to read input\n", 23);
        return 1;
    }

    //open phonebook file for appending (create if doesn't exist)
    int fd = open(PHONEBOOK_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        write(STDERR_FILENO, "Failed to open phonebook file\n", 31);
        return 1;
    }

    //write input to file
    ssize_t written = write(fd, buffer, bytes_read);
    if (written != bytes_read) {
        write(STDERR_FILENO, "Failed to write to phonebook file\n", 35);
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}