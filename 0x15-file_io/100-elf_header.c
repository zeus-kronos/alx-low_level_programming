#include <elf.h>
#include "main.h"
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))
/**
* verify- verify the file to check if is a ELF
* @e_ident: the ELF struct
* return: no return is a void func.
*/

void verify(unsigned char *e_ident)
{
	if (*(e_ident) == 0x7f && *(e_ident + 1) == 'E' &&
	    *(e_ident + 2) == 'L' && *(e_ident + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
		exit(98);
	}
}

/**
* magic - print magic number
* @e_ident: the ELF struct
* return: no return is a void func.
*/

void magic(unsigned char *e_ident)
{
	int i; /* the index to count the magic bytes */
	int limit;

	limit = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (i = 0; i < limit; i++)
		printf("%02x ", *(e_ident + i));
	printf("%02x\n", *(e_ident + i));
}

/**
* class - print the class of the ELF
* @e_ident: the ELF struct
* return: no return is a void func.
*/

void class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
* data - print mthe type of data
* @e_ident: the ELF struct
* return: no return is a void func.
*/

void data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

/**
* version - print the version of the file
* @e_ident: the ELF struct
* return: no return is a void func.
*/

void version(unsigned char *e_ident)
{
	printf("  Version:                           ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", e_ident[EI_VERSION]);
}

/**
 * osabi - print the osabi
 * @e_ident: the ELF struct
 * return: no return is a void func.
 */
void osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	if (e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

/**
* type - print the type
* @e_ident: the ELF struct
* @e_type: data to compare and print.
* return: no return is a void func.
*/

void type(unsigned int e_type, unsigned char *e_ident)
{
	e_ident[EI_DATA] == ELFDATA2MSB ? e_type = e_type >> 8 : e_type;

	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

/**
* entry - print the entry point
* @e_ident: the ELF struct
* @e_entry: the data to print
* return: no return is a void func.
*/

void entry(unsigned int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_entry = REV(e_entry);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)e_entry);
}

/**
* main - read a ELF file.
* @argc: the number of args
* @argv: the Args
* section header: the header of this function is holberton.h
* Return: 0 in success
*/

int main(int argc, char *argv[])
{
	int fd, _read, _close;
	Elf64_Ehdr *file;

	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_read = read(fd, file, sizeof(Elf64_Ehdr));
	if (_read == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	verify(file->e_ident);
	magic(file->e_ident);
	class(file->e_ident);
	data(file->e_ident);
	version(file->e_ident);
	osabi(file->e_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->e_ident[EI_ABIVERSION]);
	type(file->e_type, file->e_ident);
	entry(file->e_entry, file->e_ident);
	free(file);
	_close = close(fd);
	if (_close)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}
	return (0);
}
