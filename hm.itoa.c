#include "shell.h"

/**
 *_ft_abs - abs.
 *@nb: arg 1.
 *Return: pos num.
 */
static int	_ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/**
 *_ft_num_pow - pow.
 *@nbr: arg 1.
 *Return: pow.
 */
static int	_ft_num_pow(int nbr)
{
	int	pow;

	pow = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		pow++;
	}
	return (pow);
}

/**
 *the_itoa - int to array of chars.
 *@n: arg 1.
 *Return: string.
 */
char	*the_itoa(int n)
{
	char	*res;
	int		len;
	int		neg;

	neg = n < 0;
	len = _ft_num_pow(n) + neg;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = _ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
