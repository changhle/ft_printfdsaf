#include "ft_printf"

int	print_s(t_flag flag, va_list ap)
{
	int		ret;
	int		str_len;
	char	*str;

	ret = 0;
	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (flag->precision < str_len && flag->precision > -1)
		str_len = flag->precision;
	if (flag->f_minus > -1)
	{
		while (str_len > ret++)// 이후 수정 가능성 있음
			write(1, (str++), 1);
		while (flag->width > ret++)
			write(1, " ", 1);
	}
	else
	{
		while (flag->width - str_len > ret++)
			write(1, " ", 1);
		while (str_len > ret++)
			write(1, (str++), 1);
	}
	return (ret);
}