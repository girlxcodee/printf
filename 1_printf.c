#include "main.h"

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
                write(1, "-", 1);
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

            write(1, num_str, num_len);
            count += num_len;

            i++;
        }
        else if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(arg);
    return count;
}

