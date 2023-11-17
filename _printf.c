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
	{
		return (-1);
	}

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
				if (*ptr == '\0')
				{
					ptr = "(null)";
					write(1, ptr, 7);
				}
				else
				{
				while (ptr[i])
					i++;
				write(1, ptr, i);
				j += i;
				}
			}

			else if (*format == 'i' || *format == 'd')
			{
				int k = va_arg(args, int);
				int len = _write(k);
				j += len - 1;
			}
			
			else
			{
				write(1, format, 1);
			}
		}
		format++;
	}
	va_end(args);
	return (j);
}
















