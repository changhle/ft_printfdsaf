#include "ft_printf.h"

int	nbr_len(int nbr)
{
	int	len;

	if (nbr >= 0)
		len = 1;
	else
	{
		nbr *= -1;
		len = 2;
	}
	while ((unsigned int)nbr > 0)
	{
		(unsigned int)nbr /= 10;
		len++;
	}
}

int	print_di(t_flag *flag, va_list ap)
{
	int	ret;
	int	nbr;
	int	nbr_len;

	ret = 0;
	nbr = va_arg(ap, int);
	nbr_len = nbr_len(nbr);
	printf("%d\n", nbr_len);
	return (ret);
}