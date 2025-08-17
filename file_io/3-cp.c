#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * print_error_exit - Prints error and exits with code
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
 * close_fd - Closes a file descriptor safely
 * @fd: The file descriptor to close
 */
void close_fd(int fd)
{
	char fd_str[12];

	if (close(fd) == -1)
	{
		sprintf(fd_str, "%d", fd);
		print_error_exit(100, "Error: Can't close fd %s\n", fd_str);
	}
}

/**
 * open_fd_from - Opens file_from and performs first read
 * @file_from: Source file name
 * @fd_from: Pointer to store opened file descriptor
 * @buffer: Buffer to read into
 *
 * Return: Number of bytes read
 */
ssize_t open_fd_from(const char *file_from, int *fd_from, char *buffer)
{
	ssize_t r_bytes;

	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);

	r_bytes = read(*fd_from, buffer, BUFFER_SIZE);
	if (r_bytes == -1)
	{
		close_fd(*fd_from);
		print_error_exit(98, "Error: Can't read from file %s\n", file_from);
	}

	return (r_bytes);
}

/**
 * copy_file - Copies content from one file to another
 * @file_from: Source file
 * @file_to: Destination file
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t r_bytes, w_bytes;
	char buffer[BUFFER_SIZE];

	r_bytes = open_fd_from(file_from, &fd_from, buffer);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error_exit(99, "Error: Can't write to %s\n", file_to);
	}

	while (r_bytes > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error_exit(99, "Error: Can't write to %s\n", file_to);
		}

		r_bytes = read(fd_from, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error_exit(98, "Error: Can't read from file %s\n", file_from);
		}
	}

	close_fd(fd_from);
	close_fd(fd_to);
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
