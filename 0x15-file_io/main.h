#ifndef FILE_MAIN
#define FILE_MAIN

#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void validate_elf(unsigned char *e_ident);
unsigned int lit_to_big_endian(unsigned int x);
void print_entry(unsigned int e_type, unsigned char *e_ident);

#endif /* MAIN */
