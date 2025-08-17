#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024

int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);

#endif /* MAIN_H */
