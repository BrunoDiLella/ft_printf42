#include "ft_printf.h"

int convertHexa(size_t res)
{
    char temp;
    static int i = 0;
    int j;
    j = i;

    if (res != 0)
    {
        convertHexa(res/16);
        if (res % 16 < 10)
            temp = res % 16 + 48;
        else
            temp = res % 16 - 10 + 'a';
        write(1, &temp, 1);
        i++;
    }
    j = i - j;
    return (j);
}

int condition_p(va_list ptr)
{
    unsigned long long int res;
    int i;

    i = 0;
    res = va_arg(ptr, unsigned long long int);
    if (res == 0)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    write(1, "0x", 2);
    i = convertHexa(res);
    return (i + 2);
}
