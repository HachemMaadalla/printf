#include <unistd.h>
#include "main.h"
/**
 * _printf - printf function
 * @format: format of the input
 * Return: Print the input
 */
int _printf(const char *format, ...)
{
va_list arguments;
int i = 0;
const char *pointer;
if (format == NULL)
return (-1);
va_start(arguments, format); 
for (pointer = format; *pointer != '\0'; pointer++)
{
if (*pointer != '%')
{
	write(1, pointer, 1);
	count++;
}
else
{
	pointer++;
	char nextChar = *pointer;
if (nextChar == 'c')
{
	char c = (char) va_arg(arguments, int);
	write(1, &c, 1);
	i++;
} 
else if (nextChar == 's')
{
	char *str = va_arg(arguments, char *);
for (char *temp = str; *temp; temp++)
{
	i++;
}
write(1, str, i);
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
