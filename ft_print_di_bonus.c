#include "ft_printf.h"

int	ft_nbr_len(int nbr)
{
	int				len;
	unsigned int	u_nbr;

	if (nbr > 0)
		len = 0;
	else
	{
		nbr *= -1;
		len = 1;
	}
	u_nbr = (unsigned int)nbr;
	while (u_nbr > 0)
	{
		u_nbr /= 10;
		len++;
	}
	return (len);
}

int	print_di(t_flag *flag, va_list ap)
{
	int	ret;
	int	nbr;
	int	nbr_len;

	ret = 0;
	nbr = va_arg(ap, int);
	nbr_len = ft_nbr_len(nbr);
	printf("%d\n", nbr);
	printf("%d\n", nbr_len);
	return (ret);
}