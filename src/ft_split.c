/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:21:37 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 01:21:37 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	word;
	int	cnt;

	cnt = 0;
	word = 0;
	while (1)
	{
		if (word == 0 && *s != c)
			word = 1;
		else if (word == 1 && (*s == c || *s == '\0'))
		{
			word = 0;
			cnt++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (cnt);
}

static char	*ft_strndup(char *str, int len)
{
	char	*s;
	char	*ret_s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ret_s = s;
	while (len > 0)
	{
		*(s++) = *(str++);
		len--;
	}
	*s = '\0';
	return (ret_s);
}

static void	fill_word(char const *s, char **arr, char c)
{
	int		i;
	int		word;
	char	*start;

	i = 0;
	word = 0;
	while (1)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			start = (char *)s;
		}
		else if (word == 1 && (*s == c || *s == '\0'))
		{
			word = 0;
			arr[i++] = ft_strndup(start, s - start);
		}
		arr[i] = NULL;
		if (*s == '\0')
			break ;
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!arr)
		return (NULL);
	fill_word(s, arr, c);
	return (arr);
}
