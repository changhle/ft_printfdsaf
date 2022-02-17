#include "ft_printf.h"

int	print_percent_space(t_flag *flag)
{
	int	ret;
	
	ret = 1;
	if (!(flag->f_minus > -1) && flag->f_zero > -1)
	{
		while (flag->width > ret++)
			write(1, "0", 1);
	}
	else
	{
		while (flag->width > ret++)
			write(1, " ", 1);
	}
	return (ret);
}

int	print_percent(t_flag *flag)
{
	int	ret;

	ret = 0;
	if (flag->f_minus > -1)
	{
		write(1, "%", 1);
		ret = print_percent_space(flag);
	}
	else
	{
		ret = print_percent_space(flag);
		write (1, "%", 1);
	}
	return (ret);
}
