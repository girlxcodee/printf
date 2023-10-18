#include "main.h"
/**
 * _printf - Custom implementation of the printf function
 * @format: The format string to process
 * Description:
 * This function processes a format string and produces output based on the
 * provided format specifiers. It handles the %c, %s, %%, %d, and %i specifiers.
 * It calls the _putchar function to print characters.
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
            int num_len = 0;

            if (num < 0)
            {
                _putchar('-');
                count++;
                num = -num;
            }

            int temp = num;
            do
            {
                temp /= 10;
                num_len++;
            } while (temp);

            char num_str[12];

            for (int j = num_len - 1; j >= 0; j--)
            {
                num_str[j] = num % 10 + '0';
                num /= 10;
            }

            for (int j = 0; j < num_len; j++)
            {
                _putchar(num_str[j]);
                count++;
            }

            i++;
        }
        else if (format[i] == '%' && (format[i + 1] == 'c'))
        {
            char c = (char)va_arg(arg, int);
            _putchar(c);
            count++;
            i++; // Skip the specifier character
        }
        else if (format[i] == '%' && (format[i + 1] == 's'))
        {
            char *str = va_arg(arg, char *);
            for (int j = 0; str[j] != '\0'; j++)
            {
                _putchar(str[j]);
                count++;
            }
            i++;
        }
        else if (format[i] == '%' && (format[i + 1] == '%'))
        {
            _putchar('%');
            count++;
            i++;
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

