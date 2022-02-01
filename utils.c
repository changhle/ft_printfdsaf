#include "ft_printf.h"

void	ft_putunbr(unsigned int u)
{
	char	c;

	if (u > 9)
	{
		ft_putunbr(u / 10);
		c = u % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = u % 10 + '0';
		write(1, &c, 1);
	}
}