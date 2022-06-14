#include "ft_printf.h"

int condition_di(va_list ptr)
{
    char *x;
    int y;

    y = 0;
    x = ft_itoa(va_arg(ptr, int));
    while(x[y])
    {
        write(1, &x[y], 1);
        y++;
    }
    free(x);

    return (y);
}