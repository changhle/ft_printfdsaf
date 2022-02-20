#include "ft_printf.h"

int	print_s(t_flag *flag, va_list ap)
{
	int		ret;
	int		str_len;
	char	*str;

	ret = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(str);
	if (flag->precision < str_len && flag->dot == 1)
		str_len = flag->precision;
	if (flag->f_minus > -1)
	{
		while (str_len > ret)// 이후 수정 가능성 있음
		{
			write(1, (str++), 1);
			ret++;
		}
		while (flag->width > ret)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		while (flag->width - str_len > ret)
		{
			if (flag->f_zero > -0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			ret++;
		}
		while (str_len-- > 0)
		{
			write(1, (str++), 1);
			ret++;
		}
	}
	return (ret);
}