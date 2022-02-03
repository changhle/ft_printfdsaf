#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (format[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			if (format[i] == 'p')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
			}
			if (format[i] == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (format[i] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (format[i] == 'u')
				ft_putunbr(va_arg(ap, unsigned int));
			if (format[i] == 'x')
			{
			}
			if (format[i] == 'X')
			{
			}
			if (format[i] == '%')
				write(1, "%", 1);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	void *a, *b;

	ft_printf("%c %s %d %% %u %u %p %p Hello World!\n", 'A', "string", 42, -1, 4294967296, a, b);
	printf("%p %p %x %x\n", a, b, 100, -1141564635438400);
}