#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "src/libft.h"

typedef struct	s_flag
{
	int	f_minus;
	int	f_plus;
	int	f_zero;
	int	f_hash;
	int	f_space;
	int	width;
	int	precision;
	int	type;
}	t_flag;

int	print_percent(t_flag *flag);
int	print_c(t_flag *flag, va_list ap);

#endif