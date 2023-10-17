#include "t_main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 *
 * Description:
 * This function processes a format string and produces output
 * based on the provided format specifiers. It handles the '%c',
 * '%s', and '%%' specifiers and prints other characters as-is.
 *
 * Return:
 * On success, the function returns the number of characters
 * printed (excluding the null byte). If an error occurs, it
 * returns -1 for a NULL format parameter.
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (-1);
	}
	int count;
	int i;
	int n;
	const char *str;

	va_list arg;
		va_start(arg, format);

		count = 0;
		i = 0;

		while (format[i] != '\0')
		{
			/* Character Handling - Print character as-is */
			if (format[i] != '%')
			{
				if (format[i] != '\0')
				{
					_putchar(format[i]);
					count++;
				}
				i++;
			}
			else if (format[i] == '%')
			{
				i++;
				if (format[i] == '\0')
					break;

				else if (format[i] == '%')
				{
					/* Handle '%%' specifier - Print '%' character */
					_putchar('%');
					count++;
					i++;
				}

				if (format[i] == 'c')
				{
					/* Handle '%c' specifier - Print character from args */
					_putchar(va_arg(arg, int));
					count++;
					i++;
				}

				else if (format[i] == 's')
				{
					/* Handle '%s' specifier - Print string from args */
						str = va_arg(arg, char *);
				 for (n = 0; str[n]; n++)
					{
						_putchar(str[n]);
					count++;
					}
					i++;
				}
			else
			{
				/* Handle invalid specifier - Print '%' character */
				_putchar('%');
				count++;
				i++;
			}
		}
	}
		va_end(arg);
		return (count);
}

