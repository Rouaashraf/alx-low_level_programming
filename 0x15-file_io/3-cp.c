#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * @brief Prints error message corresponding to error code and exits program.
 *
 * @param error_code The error code indicating the type of error.
 * @param error_message The error message to be displayed.
 */
void error_and_exit(int error_code, const char *error_message)
{
	perror(error_message);
	exit(error_code);
}

/**
 * @brief Copies the contents of the source file to the destination file.
 *
 * @param file_from The path of the source file.
 * @param file_to The path of the destination file.
 */

void cp_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_and_exit(99, "Error opening the source file");

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_and_exit(99, "Error opening/creating the destination file");

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
			error_and_exit(99, "Error writing to the destination file");
	}
	if (bytes_read == -1)
		error_and_exit(99, "Error reading the source file");

	if (close(fd_from) == -1)
		error_and_exit(99, "Error closing the source file");

	if (close(fd_to) == -1)
		error_and_exit(99, "Error closing the destination file");
}
