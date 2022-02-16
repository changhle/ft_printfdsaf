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
	int	space;
	int	width;
	int	precision;
	int	type;
}	t_flag;

#endif