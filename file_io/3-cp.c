#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Print error message to stderr and exit with a given code.
 * @code: Exit code.
 * @message: Error message format string.
 * @arg: Optional argument to the format string.
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - Entry point for cp command that copies one file to another.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, exits on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
		error_exit(97, "Usage: %s file_from file_to\n", av[0]);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", av[2]);
		}
	}
	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", av[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", av[1]);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", av[2]);

	return (0);
}
