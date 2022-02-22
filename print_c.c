#include "ft_printf.h"

int	print_c_space(t_flag *flag)
{
	int	ret;

	ret = 1;
	if (!(flag->f_minus > -1) && flag->f_zero > -1)
	{
		while (flag->width > ret)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (flag->width > ret)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	print_c(t_flag *flag, va_list ap)
{
	int		ret;
	char	c;

	ret = 0;
	c = (char)va_arg(ap, int);
	if (flag->f_minus > -1)
	{
		write(1, &c, 1);
		ret = print_c_space(flag);
	}
	else
	{
		ret = print_c_space(flag);
		write(1, &c, 1);
	}
	return (ret);
}
