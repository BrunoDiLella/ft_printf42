#include "ft_printf.h"

int convertHexUp(size_t res)
{
    char temp;
    static int i = 0;
    int j;
    j = i;

    if (res != 0)
    {
        convertHexUp(res/16);
        if (res % 16 < 10)
            temp = res % 16 + 48;
        else
            temp = res % 16 - 10 + 'a' - 32;
        write(1, &temp, 1);
        i++;
    }
    j = i - j;
    return (j);
}

int convertHex(size_t res)
{
    char temp;
    static int i = 0;
    int j;
    j = i;

    if (res != 0)
    {
        convertHex(res/16);
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

int condition_x(va_list ptr, char c)
{
    unsigned int res;
    int i;

    i = 0;
    res = va_arg(ptr, unsigned int);
    if (res == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (c == 'X')
        i = convertHexUp(res);
    else
        i = convertHex(res);
    return (i);
}
