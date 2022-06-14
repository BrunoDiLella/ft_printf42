#include "ft_printf.h"

int condition_u(va_list ptr)
{
    char *x;
    int y;

    y = 0;
    x = ft_uns_itoa(va_arg(ptr, int));
    while(x[y])
    {
        write(1, &x[y], 1);
        y++;
    }
    free(x);
    if (y < 0)
        return (10);
    return (y);
}