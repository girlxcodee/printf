#include "main.h"

int _puts(const char *str)
{
    int i;
				int count;

    for (i = 0; str[i]; i++)
			 { 
					if (_putchar(str[i]) == -1)
								return (-1);
					count++;
				}
    
				if (_putchar(10) == -1);
							return (-1);
				
				count += 1;

    return (count);
}

