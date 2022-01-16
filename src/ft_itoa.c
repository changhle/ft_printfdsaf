/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:19:16 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 01:19:16 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int				len;
	unsigned int	unsigned_n;

	if (n == 0)
		return (1);
	else if (n > 0)
		len = 1;
	else
	{
		n *= -1;
		len = 2;
	}
	unsigned_n = n;
	while (unsigned_n > 9)
	{
		unsigned_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	unsigned_n;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		*str = 48;
	else if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	unsigned_n = n;
	while (unsigned_n > 0)
	{
		str[len - 1] = unsigned_n % 10 + 48;
		unsigned_n /= 10;
		len--;
	}
	return (str);
}
