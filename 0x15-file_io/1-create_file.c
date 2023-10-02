#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file with the given content.
 * @filename: Name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, write_count, len = 0;

    if (!filename)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (!text_content)
    {
        close(fd);
        return (1);
    }

    while (text_content[len])
        len++;

    write_count = write(fd, text_content, len);
    close(fd);

    if (write_count == -1 || write_count != len)
        return (-1);

    return (1);
}

