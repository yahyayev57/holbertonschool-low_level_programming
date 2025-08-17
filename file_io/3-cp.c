#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error_exit - Prints error and exits with code
 * @code: Exit code
 * @msg: Error message format
 * @arg: Argument for error message
 */
void print_error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * copy_file - Copies contents from one file to another
 * @file_from: Source file name
 * @file_to: Destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r_bytes, w_bytes;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);

	r_bytes = read(fd_from, buffer, 1024);
	if (r_bytes == -1)
	{
		close(fd_from);
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	while (r_bytes > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			print_error_exit(99, "Error: Can't write to %s\n", file_to);
		}
		r_bytes = read(fd_from, buffer, 1024);
		if (r_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error_exit(98, "Error: Can't read from file %s\n", file_from);
		}
	}

	if (close(fd_from) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
		print_error_exit(100, "Error: Can't close fd %d\n", fd_to);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_exit(97, "Usage: cp file_from file_to\n", "");

	copy_file(argv[1], argv[2]);
	return (0);
}
