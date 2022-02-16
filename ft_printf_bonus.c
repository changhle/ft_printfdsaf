#include "ft_printf.h"

int	print(t_flag flag, va_list ap)
{
	int	ret;

	ret = 0;
	if (flag->type == 'c')
		ret = print_c(flag, ap);
	else if (flag->type == 's')
		ret = print_s(flag, ap);
	else if (flag->type == 'p')
		ret = print_p(flag, ap);
	else if (flag->type == 'd' || flag->type == 'i')
		ret = print_di(flag, ap);
	else if (flag->type == 'u')
		ret = print_u(flag, ap);
	else if (flag->type == 'x' flag->type == 'X')
		ret = print_xX(flag, ap);
	else if (flag->type == '%')
		ret = print_percent(flag);
	return (ret);
}

void	parse(const char *format, int *index, t_flag flag)
{
	(*index)++;
	while (ft_strchr("-0#+ ", format[*index]))
		(*index)++;
	while (ft_strchr("0123456789", format[*index]))
	{
		flag->width *= 10 + format[*index] - '0';
		(*index)++;
	}
	if (format[*index] == '.')
	{
		(*index)++;
		while (ft_strchr("0123456789", format[*index]))
		{
			flag->precision *= 10 + foramt[*index] - '0';
			(*index)++;
		}
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
		flag->type = format[*index];
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		ret;
	va_list	ap;
	t_flag	flag;

	va_start(ap, format);
	index = 0;
	ret = 0;
	flag = malloc(sizeof(t_flag));
	init_flag(flag);
	while (format[index])
	{
		if (format[index] == '%')
		{
			parse(format, &index, flag);
			ret += print(flag, ap);
		}
		else
			write(1, &format[index++], 1);
		index++;
	}
	free();
	return (ret);
}

/* int	main(void)
{
	void *a, *b;

	ft_printf("%c %s %d %% %u %u %p %p Hello World!\n", 'A', "string", 42, -1, 4294967296, a, b);
	printf("%p %p %x %x\n", a, b, 100, -1141564635438400);
} */