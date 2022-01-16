#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, )
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar_fd(va_arg(ap, char), 1);
			if (format[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			if (format[i] == 'p')
			{
			}
			if (format[i] == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (format[i] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (format[i] == 'u')
			{
			}
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
}