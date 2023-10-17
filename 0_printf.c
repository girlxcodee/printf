#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 *
 * Description:
 * This function processes a format string and produces output
 * based on the provided format specifiers. It handles the '%c',
 * '%s', and '%%' specifiers and prints other characters as-is.
 *
 * Return: always count at success.
	* returns -1 for a NULL format parameter.
 */

int _printf(const char *format, ...)
{
	int count;	int i;

	va_list arg;
		va_start(arg, format);

		i = 0;	count = 0;
		if (format == NULL) return (-1);
		while (format[i] != '\0')
		{
			if (format[i] != '%')
			{ 
				if (format[i] != '\0')
				{
				_putchar(format[i]);	count++;
				}i++;
			}
			else if (format[i] == '%')
			{i++;
				if (format[i] == '\0')	break;
				
				else if (format[i] == '%')
				{
					_putchar('%');	count++;
					i++;}
				if (format[i] == 'c')
				{
					_putchar(va_arg(arg, int)); count++;	i++;
				}
			}	
		}
		return (count);
}

