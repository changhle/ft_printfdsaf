/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:21:48 by changhle          #+#    #+#             */
/*   Updated: 2021/12/07 03:48:38 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		i = 0;
		while (i < len)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
