#include "ft_printf.h"

int	ft_writechar(char c, int n)
{
	write(1, &c, n);
	return (0);
}

int	check_char(const char *s, va_list ptr)
{
	int i;
	int len;
	int count;
	int var;

	len = 0;
	var = 0;
	i = 0;
	count = 0;

 	while (s[i])
	{
		if (s[i] == '%')
		{
			count = ft_is_character(s[i + 1], ptr);
			i += 2;
		}
		if (s[i] && s[i] != '%')
		{
			ft_writechar(s[i], 1);
			i++;
			len++;
		}
		var += count;
		count = 0;
	}
	return (len + var);
}

int	ft_printf(const char *s, ...)
{
	va_list ptr;
	int len;

	len = 0;
	if (!s)
		return (0);
	va_start(ptr, s);
	len = check_char(s, ptr);
	va_end(ptr);
	return(len);	
}
