#include "ft_printf.h"

int condition_c(va_list ptr)
{
    int res;

    res = va_arg(ptr, int);

    write(1, &res, 1);

    return (1);
}
