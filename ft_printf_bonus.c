#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->f_minus = -1;
	flag->f_plus = -1;
	flag->f_zero = -1;
	flag->f_hash = -1;
	flag->f_space = -1;
	flag->width = 0;
	flag->dot = -1;
	flag->precision = 0;
	flag->type = 0;
}

void	set_flag(const char *format, int index, t_flag *flag)
{
	if (format[index] == '-')
		flag->f_minus = index;
	else if (format[index] == '0')
		flag->f_zero = index;
	else if (format[index] == '#')
		flag->f_hash = index;
	else if (format[index] == '+')
		flag->f_plus = index;
	else if (format[index] == ' ')
		flag->f_space = index;
}

int	print(t_flag *flag, va_list ap)
{
	int	ret;

	ret = 0;
	if (flag->type == 'c')
		ret = print_c(flag, ap);
	else if (flag->type == 's')
		ret = print_s(flag, ap);
	// else if (flag->type == 'p')
	// 	ret = print_p(flag, ap);
	else if (flag->type == 'd' || flag->type == 'i')
		ret = print_di(flag, ap);
	// else if (flag->type == 'u')
	// 	ret = print_u(flag, ap);
	// else if (flag->type == 'x' flag->type == 'X')
	// 	ret = print_xX(flag, ap);
	else if (flag->type == '%')
		ret = print_percent(flag);
	return (ret);
}

void	parse(const char *format, int *index, t_flag *flag)
{
	(*index)++;
	init_flag(flag);
	while (ft_strchr("-0#+ ", format[*index]))
	{
		set_flag(format, *index, flag);
		(*index)++;
	}
	while (ft_strchr("0123456789", format[*index]))
	{
		flag->width = flag->width * 10 + format[*index] - '0';
		(*index)++;
	}
	if (format[*index] == '.')
	{
		flag->dot = index;
		(*index)++;
		while (ft_strchr("0123456789", format[*index]))
		{
			flag->precision = flag->precision * 10 + format[*index] - '0';
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
	t_flag	*flag;

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
			write(1, &format[index], 1);
		index++;
	}
	free(flag);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	ft_printf("%-05%0\n");
	ft_printf("%05%0\n");
	ft_printf("%-5%0\n");
	ft_printf("%5c0\n", 'a');
	ft_printf("%05c0\n", 'a');
	ft_printf("%-05c0\n", 'a');
	ft_printf("%-5c0\n", 'a');
	ft_printf("%5s0\n", "abc");
	ft_printf("%2s0\n", "abc");
	ft_printf("%05s0\n", "abc");
	ft_printf("%02s0\n", "abc");
	ft_printf("%.5s0\n", "abc");
	ft_printf("%5.5s0\n", "abc");
	ft_printf("%5.1s0\n", "abc");
	ft_printf("%2.5s0\n", "abc");
	ft_printf("%2.1s0\n", "abc");
	ft_printf("------------------\n");
	ft_printf("%-5s0\n", "abc");
	ft_printf("%-2s0\n", "abc");
	ft_printf("%-05s0\n", "abc");
	ft_printf("%-02s0\n", "abc");
	ft_printf("%-.5s0\n", "abc");
	ft_printf("%-5.5s0\n", "abc");
	ft_printf("%-5.1s0\n", "abc");
	ft_printf("%-2.5s0\n", "abc");
	ft_printf("%-2.1s0\n", "abc");
	printf("-----di-----\n");
	ft_printf("%d\n", 123);
	ft_printf("%d\n", 2147483648);
	ft_printf("%d\n", -123);
	ft_printf("%d\n", -2147483649);
}

/* int	main(void)
{
	void *a, *b;

	ft_printf("%c %s %d %% %u %u %p %p Hello World!\n", 'A', "string", 42, -1, 4294967296, a, b);
	printf("%p %p %x %x\n", a, b, 100, -1141564635438400);
	printf("%d", 0x14)
} */
