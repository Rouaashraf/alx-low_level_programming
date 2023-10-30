#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/**
 * error_and_exit - Print error message and exit with the given code
 * @code: Exit code
 * @message: Error message
 */
void error_and_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * cp_file - Copy the content of a file to another file
 * @file_from: Source file name
 * @file_to: Destination file name
 */
void cp_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_and_exit(98, "Error: Can't read from file");

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_and_exit(99,
