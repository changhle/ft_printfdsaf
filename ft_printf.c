#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->f_minus = -1;
	flag->f_plus = -1;
	flag->f_zero = -1;
	flag->f_hash = -1;
	flag->f_space = -1;
	flag->width = 0;
	flag->dot = 0;
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
	else if (flag->type == 'u')
		ret = print_u(flag, ap);
	else if (flag->type == 'x' || flag->type == 'X')
		ret = print_xX(flag, ap);
	else if (flag->type == '%')
		ret = print_percent(flag);
	return (ret);
}

void	parse(const char *format, int *index, t_flag *flag)
{
	(*index)++;
	init_flag(flag);
	// printf("\n\nbefore-- %d %d %d %d %d %d %d %d %d\n", flag->f_minus, flag->f_plus, flag->f_zero, flag->f_hash, flag->f_space, flag->width, flag->dot, flag->precision, flag->type);
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
		flag->dot = 1;
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
	while (format[index])
	{
		if (format[index] == '%')
		{
			parse(format, &index, flag);
			// printf("after-- %d %d %d %d %d %d %d %d %d\n", flag->f_minus, flag->f_plus, flag->f_zero, flag->f_hash, flag->f_space, flag->width, flag->dot, flag->precision, flag->type);
			ret += print(flag, ap);
		}
		else
		{
			write(1, &format[index], 1);
			ret++;
		}
		index++;
	}
	va_end(ap);
	free(flag);
	return (ret);
}

/* int	main(void)
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
} */

/* int	main(void)
{
	// printf("--%d\n", printf("%c", '0'));
	// printf("--%d\n", printf(" %c ", '0'));
	// printf("--%d\n", printf(" %c", '0' - 256));
	// printf("--%d\n", printf("%c ", '0' + 256));
	// printf("--%d\n", printf(" %c %c %c ", '0', 0, '1'));
	// printf("--%d\n", printf(" %c %c %c ", ' ', ' ', ' '));
	// printf("--%d\n", printf(" %c %c %c ", '1', '2', '3'));
	// printf("--%d\n", printf(" %c %c %c ", '2', '1', 0));
	// printf("--%d\n", printf(" %c %c %c ", 0, '1', '2'));
	// printf("-----------------------\n");
	// printf("--%d\n", ft_printf("%c", '0'));
	// printf("--%d\n", ft_printf(" %c ", '0'));
	// printf("--%d\n", ft_printf(" %c", '0' - 256));
	// printf("--%d\n", ft_printf("%c ", '0' + 256));
	// printf("--%d\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	// printf("--%d\n", ft_printf(" %c %c %c ", ' ', ' ', ' '));
	// printf("--%d\n", ft_printf(" %c %c %c ", '1', '2', '3'));
	// printf("--%d\n", ft_printf(" %c %c %c ", '2', '1', 0));
	// printf("--%d\n", ft_printf(" %c %c %c ", 0, '1', '2'));
	// printf("--%d\n", printf(" %% "));
	// printf("--%d\n", printf(" %%%% "));
	// printf("--%d\n", printf(" %% %% %% "));
	// printf("--%d\n", printf(" %%  %%  %% "));
	// printf("--%d\n", printf(" %%   %%   %% "));
	// printf("--%d\n", printf("%%"));
	// printf("--%d\n", printf("%% %%"));
	// printf("----------------------\n");
	// printf("--%d\n", ft_printf(" %% "));
	// printf("--%d\n", ft_printf(" %%%% "));
	// printf("--%d\n", ft_printf(" %% %% %% "));
	// printf("--%d\n", ft_printf(" %%  %%  %% "));
	// printf("--%d\n", ft_printf(" %%   %%   %% "));
	// printf("--%d\n", ft_printf("%%"));
	// printf("--%d\n", ft_printf("%% %%"));
	// char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// printf("--%d\n", printf("%s", ""));
	// printf("--%d\n", printf(" %s", ""));
	// printf("--%d\n", printf("%s ", ""));
	// printf("--%d\n", printf(" %s ", ""));
	// printf("--%d\n", printf(" %s ", "-"));
	// printf("--%d\n", printf(" %s %s ", "", "-"));
	// printf("--%d\n", printf(" %s %s ", " - ", ""));
	// printf("--%d\n", printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
	// printf("--%d\n", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	// printf("--%d\n", printf(" NULL %s NULL ", NULL));
	// printf("-----------------------\n");
	// printf("--%d\n", ft_printf("%s", ""));
	// printf("--%d\n", ft_printf(" %s", ""));
	// printf("--%d\n", ft_printf("%s ", ""));
	// printf("--%d\n", ft_printf(" %s ", ""));
	// printf("--%d\n", ft_printf(" %s ", "-"));
	// printf("--%d\n", ft_printf(" %s %s ", "", "-"));
	// printf("--%d\n", ft_printf(" %s %s ", " - ", ""));
	// printf("--%d\n", ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
	// printf("--%d\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	// printf("--%d\n", ft_printf(" NULL %s NULL ", NULL));
	// printf("--%d\n", printf(" %.s ", "-"));
	// printf("--%d\n", ft_printf(" %.s ", "-"));
	// printf("--%d\n", printf(" %d ", 0));
	// printf("--%d\n", printf(" %d ", -1));
	// printf("--%d\n", printf(" %d ", 1));
	// printf("--%d\n", printf(" %d ", 9));
	// printf("--%d\n", printf(" %d ", 10));
	// printf("--%d\n", printf(" %d ", 11));
	// printf("--%d\n", printf(" %d ", 15));
	// printf("--%d\n", printf(" %d ", 16));
	// printf("--%d\n", printf(" %d ", 17));
	// printf("--%d\n", printf(" %d ", 99));
	// printf("--%d\n", printf(" %d ", 100));
	// printf("--%d\n", printf(" %d ", 101));
	// printf("--%d\n", printf(" %d ", -9));
	// printf("--%d\n", printf(" %d ", -10));
	// printf("--%d\n", printf(" %d ", -11));
	// printf("--%d\n", printf(" %d ", -14));
	// printf("--%d\n", printf(" %d ", -15));
	// printf("--%d\n", printf(" %d ", -16));
	// printf("--%d\n", printf(" %d ", -99));
	// printf("--%d\n", printf(" %d ", -100));
	// printf("--%d\n", printf(" %d ", -101));
	// // printf("--%d\n", printf(" %d ", INT_MAX));
	// // printf("--%d\n", printf(" %d ", INT_MIN));
	// // printf("--%d\n", printf(" %d ", LONG_MAX));
	// // printf("--%d\n", printf(" %d ", LONG_MIN));
	// // printf("--%d\n", print(" %d ", UINT_MAX));
	// // printf("--%d\n", printf(" %d ", ULONG_MAX));
	// // printf("--%d\n", printf(" %d ", 9223372036854775807LL));
	// // printf("--%d\n", printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("--------------------------------------------\n");
	// printf("--%d\n", ft_printf(" %d ", 0));
	// printf("--%d\n", ft_printf(" %d ", -1));
	// printf("--%d\n", ft_printf(" %d ", 1));
	// printf("--%d\n", ft_printf(" %d ", 9));
	// printf("--%d\n", ft_printf(" %d ", 10));
	// printf("--%d\n", ft_printf(" %d ", 11));
	// printf("--%d\n", ft_printf(" %d ", 15));
	// printf("--%d\n", ft_printf(" %d ", 16));
	// printf("--%d\n", ft_printf(" %d ", 17));
	// printf("--%d\n", ft_printf(" %d ", 99));
	// printf("--%d\n", ft_printf(" %d ", 100));
	// printf("--%d\n", ft_printf(" %d ", 101));
	// printf("--%d\n", ft_printf(" %d ", -9));
	// printf("--%d\n", ft_printf(" %d ", -10));
	// printf("--%d\n", ft_printf(" %d ", -11));
	// printf("--%d\n", ft_printf(" %d ", -14));
	// printf("--%d\n", ft_printf(" %d ", -15));
	// printf("--%d\n", ft_printf(" %d ", -16));
	// printf("--%d\n", ft_printf(" %d ", -99));
	// printf("--%d\n", ft_printf(" %d ", -100));
	// printf("--%d\n", ft_printf(" %d ", -101));
	// // printf("--%d\n", ft_printf(" %d ", INT_MAX));
	// // printf("--%d\n", ft_printf(" %d ", INT_MIN));
	// // printf("--%d\n", ft_printf(" %d ", LONG_MAX));
	// // printf("--%d\n", ft_printf(" %d ", LONG_MIN));
	// // printf("--%d\n", ft_print(" %d ", UINT_MAX));
	// // printf("--%d\n", ft_printf(" %d ", ULONG_MAX));
	// // printf("--%d\n", ft_printf(" %d ", 9223372036854775807LL));
	// // printf("--%d\n", ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("--%d\n", printf(" %01d ", 0));
	// printf("--%d\n", printf(" %02d ", -1));
	// printf("--%d\n", printf(" %04d ", 9));
	// printf("--%d\n", printf(" %01d ", 10));
	// printf("--%d\n", printf(" %02d ", 11));
	// printf("--%d\n", printf(" %03d ", 15));
	// printf("--%d\n", printf(" %04d ", 16));
	// printf("--%d\n", printf(" %05d ", 17));
	// printf("--%d\n", printf(" %01d ", 99));
	// printf("--%d\n", printf(" %02d ", 100));
	// printf("--%d\n", printf(" %03d ", 101));
	// printf("--%d\n", printf(" %01d ", -9));
	// printf("--%d\n", printf(" %02d ", -10));
	// printf("--%d\n", printf(" %03d ", -11));
	// printf("--%d\n", printf(" %04d ", -14));
	// printf("--%d\n", printf(" %05d ", -15));
	// printf("--%d\n", printf(" %06d ", -16));
	// printf("--%d\n", printf(" %01d ", -99));
	// printf("--%d\n", printf(" %02d ", -100));
	// printf("--%d\n", printf(" %03d ", -101));
	// printf("--%d\n", printf(" %09d ", INT_MAX));
	// printf("--%d\n", printf(" %010d ", INT_MIN));
	// printf("--%d\n", printf(" %011d ", LONG_MAX));
	// printf("--%d\n", printf(" %012d ", LONG_MIN));
	// printf("--%d\n", printf(" %013d ", UINT_MAX));
	// printf("--%d\n", printf(" %d %d %d ", 1, 2, 3));
	// printf("--%d\n", printf(" %014d ", ULONG_MAX));
	// printf("--%d\n", printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("-----------------------\n");
	// printf("--%d\n", ft_printf(" %01d ", 0));
	// printf("--%d\n", ft_printf(" %02d ", -1));
	// printf("--%d\n", ft_printf(" %04d ", 9));
	// printf("--%d\n", ft_printf(" %01d ", 10));
	// printf("--%d\n", ft_printf(" %02d ", 11));
	// printf("--%d\n", ft_printf(" %03d ", 15));
	// printf("--%d\n", ft_printf(" %04d ", 16));
	// printf("--%d\n", ft_printf(" %05d ", 17));
	// printf("--%d\n", ft_printf(" %01d ", 99));
	// printf("--%d\n", ft_printf(" %02d ", 100));
	// printf("--%d\n", ft_printf(" %03d ", 101));
	// printf("--%d\n", ft_printf(" %01d ", -9));
	// printf("--%d\n", ft_printf(" %02d ", -10));
	// printf("--%d\n", ft_printf(" %03d ", -11));
	// printf("--%d\n", ft_printf(" %04d ", -14));
	// printf("--%d\n", ft_printf(" %05d ", -15));
	// printf("--%d\n", ft_printf(" %06d ", -16));
	// printf("--%d\n", ft_printf(" %01d ", -99));
	// printf("--%d\n", ft_printf(" %02d ", -100));
	// printf("--%d\n", ft_printf(" %03d ", -101));
	// printf("--%d\n", ft_printf(" %09d ", INT_MAX));
	// printf("--%d\n", ft_printf(" %010d ", INT_MIN));
	// printf("--%d\n", ft_printf(" %011d ", LONG_MAX));
	// printf("--%d\n", ft_printf(" %012d ", LONG_MIN));
	// printf("--%d\n", ft_printf(" %013d ", UINT_MAX));
	// printf("--%d\n", ft_printf(" %014d ", ULONG_MAX));
	// printf("--%d\n", ft_printf(" %09d %010d %014d %015d", INT_MAX, INT_MIN, 0, -42));
	// printf("--%d\n", ft_printf(" %d %d %d ", 1, 2, 3));
	// printf("--%d\n", ft_printf(" %c %c %c ", '1', '2', '3'));
	// printf("------------------u-----------------------\n");
	// printf("--%d\n", printf(" %u ", 0));
	// printf("--%d\n", printf(" %u ", -1));
	// printf("--%d\n", printf(" %u ", 1));
	// printf("--%d\n", printf(" %u ", 9));
	// printf("--%d\n", printf(" %u ", 10));
	// printf("--%d\n", printf(" %u ", 11));
	// printf("--%d\n", printf(" %u ", 15));
	// printf("--%d\n", printf(" %u ", 16));
	// printf("--%d\n", printf(" %u ", 17));
	// printf("--%d\n", printf(" %u ", 99));
	// printf("--%d\n", printf(" %u ", 100));
	// printf("--%d\n", printf(" %u ", 101));
	// printf("--%d\n", printf(" %u ", -9));
	// printf("--%d\n", printf(" %u ", -10));
	// printf("--%d\n", printf(" %u ", -11));
	// printf("--%d\n", printf(" %u ", -14));
	// printf("--%d\n", printf(" %u ", -15));
	// printf("--%d\n", printf(" %u ", -16));
	// printf("--%d\n", printf(" %u ", -99));
	// printf("--%d\n", printf(" %u ", -100));
	// printf("--%d\n", printf(" %u ", -101));
	// printf("---------------------------------\n");
	// printf("--%d\n", ft_printf(" %u ", 0));
	// printf("--%d\n", ft_printf(" %u ", -1));
	// printf("--%d\n", ft_printf(" %u ", 1));
	// printf("--%d\n", ft_printf(" %u ", 9));
	// printf("--%d\n", ft_printf(" %u ", 10));
	// printf("--%d\n", ft_printf(" %u ", 11));
	// printf("--%d\n", ft_printf(" %u ", 15));
	// printf("--%d\n", ft_printf(" %u ", 16));
	// printf("--%d\n", ft_printf(" %u ", 17));
	// printf("--%d\n", ft_printf(" %u ", 99));
	// printf("--%d\n", ft_printf(" %u ", 100));
	// printf("--%d\n", ft_printf(" %u ", 101));
	// printf("--%d\n", ft_printf(" %u ", -9));
	// printf("--%d\n", ft_printf(" %u ", -10));
	// printf("--%d\n", ft_printf(" %u ", -11));
	// printf("--%d\n", ft_printf(" %u ", -14));
	// printf("--%d\n", ft_printf(" %u ", -15));
	// printf("--%d\n", ft_printf(" %u ", -16));
	// printf("--%d\n", ft_printf(" %u ", -99));
	// printf("--%d\n", ft_printf(" %u ", -100));
	// printf("--%d\n", ft_printf(" %u ", -101));
	// printf("--%d\n", printf(" %x ", 0));
	// printf("--%d\n", printf(" %x ", -1));
	// printf("--%d\n", printf(" %x ", 1));
	// printf("--%d\n", printf(" %x ", 9));
	// printf("--%d\n", printf(" %x ", 10));
	// printf("--%d\n", printf(" %x ", 11));
	// printf("--%d\n", printf(" %x ", 15));
	// printf("--%d\n", printf(" %x ", 16));
	// printf("--%d\n", printf(" %x ", 17));
	// printf("--%d\n", printf(" %x ", 99));
	// printf("--%d\n", printf(" %x ", 100));
	// printf("--%d\n", printf(" %x ", 101));
	// printf("--%d\n", printf(" %x ", -9));
	// printf("--%d\n", printf(" %x ", -10));
	// printf("--%d\n", printf(" %x ", -11));
	// printf("--%d\n", printf(" %x ", -14));
	// printf("--%d\n", printf(" %x ", -15));
	// printf("--%d\n", printf(" %x ", -16));
	// printf("--%d\n", printf(" %x ", -99));
	// printf("--%d\n", printf(" %x ", -100));
	// printf("--%d\n", printf(" %x ", -101));
	// printf("--%d\n", printf(" %x ", INT_MAX));
	// printf("--%d\n", printf(" %x ", INT_MIN));
	// printf("--%d\n", printf(" %x ", LONG_MAX));
	// printf("--%d\n", printf(" %x ", LONG_MIN));
	// printf("--%d\n", printf(" %x ", UINT_MAX));
	// printf("--%d\n", printf(" %x ", ULONG_MAX));
	// // printf("--%d\n", printf(" %x ", 9223372036854775807LL));
	// printf("--%d\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("--%d\n", printf(" %x ", 42));
	// printf("--%d\n", printf(" %x ", -42));
	// printf("---------------------------------\n");
	// printf("--%d\n", ft_printf(" %x ", 0));
	// printf("--%d\n", ft_printf(" %x ", -1));
	// printf("--%d\n", ft_printf(" %x ", 1));
	// printf("--%d\n", ft_printf(" %x ", 9));
	// printf("--%d\n", ft_printf(" %x ", 10));
	// printf("--%d\n", ft_printf(" %x ", 11));
	// printf("--%d\n", ft_printf(" %x ", 15));
	// printf("--%d\n", ft_printf(" %x ", 16));
	// printf("--%d\n", ft_printf(" %x ", 17));
	// printf("--%d\n", ft_printf(" %x ", 99));
	// printf("--%d\n", ft_printf(" %x ", 100));
	// printf("--%d\n", ft_printf(" %x ", 101));
	// printf("--%d\n", ft_printf(" %x ", -9));
	// printf("--%d\n", ft_printf(" %x ", -10));
	// printf("--%d\n", ft_printf(" %x ", -11));
	// printf("--%d\n", ft_printf(" %x ", -14));
	// printf("--%d\n", ft_printf(" %x ", -15));
	// printf("--%d\n", ft_printf(" %x ", -16));
	// printf("--%d\n", ft_printf(" %x ", -99));
	// printf("--%d\n", ft_printf(" %x ", -100));
	// printf("--%d\n", ft_printf(" %x ", -101));
	// printf("--%d\n", ft_printf(" %x ", INT_MAX));
	// printf("--%d\n", ft_printf(" %x ", INT_MIN));
	// printf("--%d\n", ft_printf(" %x ", LONG_MAX));
	// printf("--%d\n", ft_printf(" %x ", LONG_MIN));
	// printf("--%d\n", ft_printf(" %x ", UINT_MAX));
	// printf("--%d\n", ft_printf(" %x ", ULONG_MAX));
	// // printf("--%d\n", ft_printf(" %x ", 9223372036854775807LL));
	// printf("--%d\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("--%d\n", ft_printf(" %x ", 42));
	// printf("--%d\n", ft_printf(" %x ", -42));
} */