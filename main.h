#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int unsigned_int_to_binary(unsigned int num, char *buffer);
void reverse_buffer(char *buffer, int len);
#endif /* MAIN_H */
