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

int	print_sign(t_flag *flag, int nbr)
{
	int	ret;

	ret = 0;
	if (flag->f_plus > -1 && nbr >= 0)
	{
		write(1, "+", 1);
		ret++;
	}
	else if (!(flag->f_plus > -1) && flag->f_space > -1 && nbr >= 0)
	{
		write(1, " " ,1);
		ret++;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ret++;
	}
	return (ret);
}

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int	print_nbr(t_flag *flag, int nbr)
{
	int	nbr_len;

	nbr_len = ft_nbr_len(nbr);
	if (nbr < 0)
		nbr_len--;
	while (flag->precision > nbr_len)
	{
		write(1, "0", 1);
		nbr_len++;
	}
	if (!flag->dot || flag->precision > 0 || nbr > 0)
		ft_putnbr(nbr);
	return (nbr_len);
}

int	print_space(t_flag *flag, int nbr)
{
	int	nbr_len;
	int	ret;

	ret = 0;
	nbr_len = ft_nbr_len(nbr);
	if (nbr < 0)
		nbr--;
	if (flag->precision > nbr_len)
		nbr_len = flag->precision;
	if (!(flag->f_minus > -1) && flag->f_zero)
	{
		while (flag->width > nbr_len + ret)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (flag->width > nbr_len + ret)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	print_di(t_flag *flag, va_list ap)
{
	int	ret;
	int	nbr;
	int	nbr_len;

	ret = 0;
	nbr = va_arg(ap, int);
	nbr_len = ft_nbr_len(nbr);
	if (flag->f_minus > -1)
	{
		ret += print_sign(flag, nbr);
		ret += print_nbr(flag, nbr);
		ret += print_space(flag, nbr);
	}
	else
	{
		ret += print_space(flag, nbr);
		ret += print_sign(flag, nbr);
		ret += print_nbr(flag, nbr);
	}
	return (ret);
}