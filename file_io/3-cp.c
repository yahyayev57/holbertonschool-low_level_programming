#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *message, const char *arg) {
    dprintf(STDERR_FILENO, message, arg);
    exit(code);
}

int main(int ac, char **av) {
    int fd_from, fd_to, r, w;
    char buffer[BUFFER_SIZE];

    if (ac != 3)
        error_exit(97, "Usage: cp file_from file_to\n", "");

    fd_from = open(av[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", av[1]);

    fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1) {
        close(fd_from);
        error_exit(98, "Error: Can't read from file %s\n", av[1]); // Changed from 99 to 98
    }

    while (1) {
        r = read(fd_from, buffer, BUFFER_SIZE);
        if (r == -1) {
            close(fd_from);
            close(fd_to);
            error_exit(98, "Error: Can't read from file %s\n", av[1]);
        }
        if (r == 0)
            break;

        w = write(fd_to, buffer, r);
        if (w == -1) {
            close(fd_from);
            close(fd_to);
            error_exit(98, "Error: Can't read from file %s\n", av[1]); // Changed from 99 to 98
        }
    }

    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}
