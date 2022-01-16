/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:22:40 by changhle          #+#    #+#             */
/*   Updated: 2021/12/07 03:47:10 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 == *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
		if (!*str1 || !*str2)
			break ;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
