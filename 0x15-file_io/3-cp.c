#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * error_handler - Handles errors and exits with the given code.
 * @exit_code: Error exit code.
 * @file: Filename causing the error.
 * @fd: File descriptor to close.
 */
void error_handler(int exit_code, char *file, int fd)
{
    if (fd > 0)
        close(fd);
    if (exit_code == 98)
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
    if (exit_code == 99)
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
    if (exit_code == 100)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    exit(exit_code);
}

/**
 * main - Entry point. Copies content from one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or one of the exit error codes.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_count, write_count;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_handler(98, argv[1], 0);
    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1)
        error_handler(99, argv[2], fd_from);
    while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        write_count = write(fd_to, buffer, read_count);
        if (write_count != read_count)
            error_handler(99, argv[2], fd_from);
    }
    if (read_count == -1)
        error_handler(98, argv[1], fd_from);
    if (close(fd_from) == -1)
        error_handler(100, NULL, fd_from);
    if (close(fd_to) == -1)
        error_handler(100, NULL, fd_to);
    return (0);
}

