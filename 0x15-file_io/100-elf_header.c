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
 * print_data - prints the data of the ELF file.
 * @data: the data byte of the ELF header.
 */
void print_data(unsigned char data)
{
    printf("  Data:                              ");
    switch (data)
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", data);
    }
}

/**
 * print_type - prints the type of the ELF file.
 * @type: the type of the ELF file.
 */
void print_type(uint16_t type)
{
    printf("  Type:                              ");
    switch (type)
    {
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    default:
        printf("<unknown: %x>\n", type);
    }
}

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error opening file\n");
        exit(98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error reading ELF header\n");
        close(fd);
        exit(98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "This is not an ELF file.\n");
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    print_magic(header.e_ident);
    printf("  Class:                             ");
    switch (header.e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
    }
    print_data(header.e_ident[EI_DATA]);
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            UNIX - System V\n");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_OSABI]);
    print_type(header.e_type);
    printf("  Entry point address:               0x%x\n", (unsigned int)header.e_entry);
    
    close(fd);
    return 0;
}
