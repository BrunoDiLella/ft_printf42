
#include "ft_printf.h"

static	int	int_size(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (2);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char	*ft_uns_itoa(unsigned int n)
{
	char			*dest;
	int				neg;
	unsigned int	size;

	neg = 0;
	size = int_size(n);
	dest = malloc(sizeof(char) * (size));
	if (!dest)
		return (NULL);
	dest[--size] = '\0';
	if (!n)
		dest[--size] = '0';
	while (n)
	{
		size--;
		dest[size] = ((-neg + !neg) * (n % 10) + 48);
		n = n / 10;
	}
	if (neg)
		dest[--size] = '-';
	return (dest);
}
