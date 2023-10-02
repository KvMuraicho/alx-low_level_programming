#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX stdout.
 * @filename: Pointer to the name of the file.
 * @letters: Number of letters the function should read and print.
 * 
 * Return: Actual number of letters it could read and print, or 0 if error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t read_len, write_len;
    char *buffer;

    
    if (filename == NULL)
        return (0);

    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    
    buffer = malloc(letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

   
    read_len = read(fd, buffer, letters);
    if (read_len == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    write_len = write(STDOUT_FILENO, buffer, read_len);
    if (write_len == -1 || write_len != read_len)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (write_len);
}

