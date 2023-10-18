#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 * Description:
 * This function processes a format string and produces output based on the
 * provided format specifiers. It handles the %d and %i specifiers.
 * Return: always returns count if successful
 * an error occurs, it returns -1 for a NULL format parameter.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i, j;
	va_list arg;
		va_start(arg, format);

	if (format == NULL)
	return (-1);
		for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int num = va_arg(arg, int);
			char num_str[12];
			int num_len = 0;

			if (num < 0)
			{
				num_str[num_len++] = '-';
				num = -num;
			}

			do {
				num_str[num_len++] = num % 10 + '0';
				num /= 10;
			} while (num > 0);

			for (j = num_len - 1; j >= 0; j--)
			{
				write(1, &num_str[j], 1);
				count++;
			} i++;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			}
		}

	va_end(arg);
	return (count);
}

