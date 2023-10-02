#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_magic - prints the magic bytes of the ELF header.
 * @e_ident: the identifier bytes of the ELF header.
 */
void print_magic(unsigned char *e_ident)
{
    int i;
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

/**
 * print_class - prints the class of the ELF file.
 * @class: the class byte of the ELF header.
 */
void print_class(unsigned char class)
{
    printf("  Class:                             ");
    switch (class)
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", class);
    }
}

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        perror("Error reading ELF header");
        close(fd);
        exit(98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || 
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "This is not an ELF file.\n");
        close(fd);
        exit(98);
    }

    print_magic(header.e_ident);
    print_class(header.e_ident[EI_CLASS]);

    close(fd);
    return 0;
}
