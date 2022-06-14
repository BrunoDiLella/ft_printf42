#include "ft_printf.h"

int condition_s(va_list ptr)
{
    char *x;
    int y;

    y = 0;
    x = va_arg(ptr, char *);
    if (x == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while(x[y])
    {
        write(1, &x[y], 1);
        y++;
    }
    return (y);
}