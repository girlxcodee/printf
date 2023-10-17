#include "t_main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 * Description:
 * This function processes a format string and produces output based on the
 * provided format specifiers. It handles the %c, %d, %i, and %% specifiers and
 * prints other characters as-is.
 * Return:
 * On success, the function returns the number of characters printed (excluding
 * the null byte). If an error occurs, it returns -1 for a NULL format parameter.
*/

int _printf(const char *format, ...)
{
   int count = 0;
    va_list arg;
    va_start(arg, format);

				if (format == NULL)
						return (-1);

				for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[++i] == '\0')
                break;
            if (format[i] == 'c')
            {
                _putchar(va_arg(arg, int));
                count++;
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(arg, int);
                if (num < 0)
                    _putchar('-'), count++;
                int temp = num < 0 ? -num : num;
                for (int divisor = 1; temp / divisor > 9; divisor *= 10);
                while (divisor)
                {
                    _putchar(temp / divisor + '0');
                    count++;
                    temp %= divisor;
                    divisor /= 10;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else
                _putchar('%'), count++;
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(arg);

    return count;
}

