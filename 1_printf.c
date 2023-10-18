#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 * Description:
 * This function processes a format string and produces output based on the
 * provided format specifiers. It handles the %d and %i specifiers and uses the
 * _putchar function to print characters.
 * Return:
 * On success, the function returns the number of characters printed (excluding
 * the null byte). If an error occurs, it returns -1 for a NULL format parameter.
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1; 

    int count = 0;
    va_list arg;
    va_start(arg, format);

    for (int i = 0; format[i] != '\0'; i++)
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

            do
            {
                num_str[num_len++] = num % 10 + '0';
                num /= 10;
            } while (num > 0);

            for (int j = num_len - 1; j >= 0; j--)
            {
                _putchar(num_str[j]);
                count++;
            }

            i++;
        }
        else if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(arg);
    return count;
}

