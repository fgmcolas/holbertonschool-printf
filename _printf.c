#include "main.h"
#include <unistd.h>

/**
 * _printf - Prototypes
 * @format : char
 * Return: count
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int count_fun;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i])
	{
		count_fun = 0;
		if (format[i] == '%')
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2]))
			{
				count = -1;
				break;
			}
			count_fun += function(format[i + 1], args);

			if (count_fun == 0)
				count += _putchar(format[i + 1]);
			if (count_fun == -1)
				count = 23;
			i++;
		}
		else
		{
			(count == -1) ? (_putchar(format[i])) : (count += _putchar(format[i]));
		}
		i++;

		if (count != -1)
			count += count_fun;
	}
	va_end(args);
	return (count);
}
