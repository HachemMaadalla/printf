#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * reverse_buffer - convert unsigned int to binary
 * @buffer: buffer
 * @len: len
 */
void reverse_buffer(char *buffer, int len)
{
int start = 0, end = len - 1;
while (start < end)
{
	char temp = buffer[start];
	buffer[start] = buffer[end];
	buffer[end] = temp;
	start++;
	end--;
}
}

/**
 * unsigned_int_to_binary - convert unsigned int to binary
 * @num: int
 * @buffer: buffer
 * Return: j
 */
int unsigned_int_to_binary(unsigned int num, char *buffer) {
int j = 0;
if (num == 0)
{
buffer[j++] = '0';
}
else
{
for (; num; num >>= 1)
{
buffer[j++] = (num & 1) + '0';
}
}
reverse_buffer(buffer, j);
return j;
}

/**
 * _printf - printf function
 * @format: format of the input
 * Return: Print the input
 */
int _printf(const char *format, ...)
{
va_list arguments;
int i = 0;
int j;
char nextChar;
char *temp;
char *str;
int number;
int len;
int len2;
int len3;
const char *pointer;
unsigned int num;
if (format == NULL)
return (-1);
va_start(arguments, format); 
for (pointer = format; *pointer != '\0'; pointer++)
{
if (*pointer != '%')
{
write(1, pointer, 1);
i++;
}
else
{
	pointer++;
	nextChar = *pointer;
if (nextChar == 'c')
{
	char c = (char) va_arg(arguments, int);
	write(1, &c, 1);
	i++;
} 
else if (nextChar == 's')
{
	str = va_arg(arguments, char *);
	len3 = 0;
for (temp = str; *temp; temp++)
{
	len3++;
}
write(1, str, len3);
i += len3;
}
else if (nextChar == 'b')
{
char buffer[33];
num = va_arg(arguments, unsigned int);
len2 = unsigned_int_to_binary(num, buffer);
for (j = 0; j < len2; j++)
{
	write(1, &buffer[j], 1);
}
i += len2;
}
else if (nextChar == 'd' || nextChar == 'i')
{
char buffer[20];
number = va_arg(arguments, int);
len = sprintf(buffer, "%d", number);
write(1, buffer, len);
i += len;
}
else if (nextChar == '%')
{
	write(1, "%", 1);
	i++;
}
else
{
	write(1, "%", 1);
	write(1, pointer, 1);
	i += 2;
}
}
}
va_end(arguments); 
return (i);
}
