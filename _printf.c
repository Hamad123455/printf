#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0,j = 0;
	char *ptr;
	char ch;
	va_list args;

	va_start(args, format);

	if (*format == '\0')
		printf("(null)");

	while (*format)
	{
		j++;
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);

			else if (*format == '%')
				write(1, format, 1);

			else if (*format == 'c')
			{
				ch = (char)va_arg(args, int);
				write(1, &ch, 1);
			}

			else if (*format == 's')
			{
				ptr = va_arg(args, char *);
				while (ptr[i])
					i++;
				write(1, ptr, i);
				j += i - 1;
			}

			else if (*format == 'i' || *format == 'd')
			{
				int k = va_arg(args, int);
				_write(k);
			}
		}
		format++;
	}
	va_end(args);
	return (j);
}
















