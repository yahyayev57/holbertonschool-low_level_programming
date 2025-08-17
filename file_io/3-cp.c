#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * print_error_exit - Prints an error and exits with code
 * @code: Exit code
 * @msg: Message format
 * @arg: Argument for message
 */
void print_error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * main - Copies contents from one file to another
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r_bytes, w_bytes;
	char buffer[BUFFER_SIZE];
	char fd_str[12];

	if (argc != 3)
		print_error_exit(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((r_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			print_error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}
	if (r_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	if (close(fd_from) == -1)
	{
		sprintf(fd_str, "%d", fd_from);
		print_error_exit(100, "Error: Can't close fd %s\n", fd_str);
	}
	if (close(fd_to) == -1)
	{
		sprintf(fd_str, "%d", fd_to);
		print_error_exit(100, "Error: Can't close fd %s\n", fd_str);
	}

	return (0);
}
