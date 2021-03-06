#include "ft_printf.h"

int	print_mark(t_flag *flag, unsigned long long xnbr)
{
	int	ret;

	ret = 0;
	if ((xnbr && flag->f_hash > -1) || flag->type == 'p')
	{
		if (flag->type == 'X')
		{
			write(1, "0X", 2);
			ret = 2;
		}
		else
		{
			write(1, "0x", 2);
			ret = 2;
		}
	}
	return (ret);
}

int	ft_xnbr_len(unsigned long long xnbr)
{
	int	len;

	len = 1;
	while (xnbr > 15)
	{
		xnbr /= 16;
		len++;
	}
	return (len);
}

void	ft_putxnbr(t_flag *flag, unsigned long long xnbr)
{
	const char	*x = "0123456789abcdef";
	const char	*X = "0123456789ABCDEF";

	if (xnbr > 15)
		ft_putxnbr(flag, xnbr / 16);
	if (flag->type == 'x' || flag->type == 'p')
		write(1, &x[xnbr % 16], 1);
	else if (flag->type == 'X')
		write(1, &X[xnbr % 16], 1);
}

int	print_xnbr(t_flag *flag, unsigned long long xnbr)
{
	int	xnbr_len;

	xnbr_len = ft_xnbr_len(xnbr);
	while (flag->precision > xnbr_len)
	{
		write(1, "0", 1);
		xnbr_len++;
	}
	if (flag->dot == 1 && flag->precision == 0 && xnbr == 0)
		return (0);
	ft_putxnbr(flag, xnbr);
	return (xnbr_len);
}

int	print_xspace(t_flag *flag, unsigned long long xnbr)
{
	int	ret;
	int	xnbr_len;

	ret = 0;
	xnbr_len = ft_xnbr_len(xnbr);
	if (flag->precision > xnbr_len)
		xnbr_len = flag->precision;
	if (flag->f_hash > -1 || flag->type == 'p')
		xnbr_len += 2;
	if (flag->dot == 1 && flag->precision == 0 && xnbr == 0)
		xnbr_len = 0;
	if (!(flag->f_minus > -1 || flag->dot == 1) && flag->f_zero > -1)
	{
		while (flag->width > xnbr_len + ret)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (flag->width > xnbr_len + ret)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	print_pxX(t_flag *flag, va_list ap)
{
	int					ret;
	unsigned long long	xnbr;

	ret = 0;
	if (flag->type == 'p')
		xnbr = va_arg(ap, unsigned long long);
	else
		xnbr = va_arg(ap, unsigned int);
	if (flag->f_minus > -1)
	{
		ret += print_mark(flag, xnbr);
		ret += print_xnbr(flag, xnbr);
		ret += print_xspace(flag, xnbr);
	}
	else
	{
		ret += print_xspace(flag, xnbr);
		ret += print_mark(flag, xnbr);
		ret += print_xnbr(flag, xnbr);
	}
	return (ret);
}
