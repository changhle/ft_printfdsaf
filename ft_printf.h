#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "src/libft.h"

typedef struct	s_flag
{
	int	f_minus;
	int	f_plus;
	int	f_zero;
	int	f_hash;
	int	f_space;
	int	width;
	int	dot;
	int	precision;
	int	type;
}	t_flag;

int	ft_printf(const char *format, ...);
int	print_percent(t_flag *flag);
int	print_c(t_flag *flag, va_list ap);
int	print_s(t_flag *flag, va_list ap);
int	print_di(t_flag *flag, va_list ap);
int	print_u(t_flag *flag, va_list ap);

#endif