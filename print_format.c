#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;  // To keep track of the number of characters printed

    while (*format) {
     if (*format != '%') {
            putchar(*format);
            char_count++;
        } else {
            format++;  // Move past the '%'
     if (*format == '\0') break;  // Handle trailing '%'

   if (*format == 'c') {
                char c = va_arg(args, int);  // Fetch the next character
                putchar(c);
                char_count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);  // Fetch the next string
                while (*s) {
                    putchar(*s);
                    s++;
                    char_count++;
                }
            } else if (*format == '%') {
                putchar('%');
                char_count++;
            } else {
                // Handle unsupported conversion specifiers
                putchar('%');
                char_count++;
                putchar(*format);
                char_count++;
            }
        }
        format++;
    }

 va_end(args);
 return char_count;
}
