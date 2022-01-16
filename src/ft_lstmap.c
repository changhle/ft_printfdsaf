/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:16:45 by changhle          #+#    #+#             */
/*   Updated: 2021/11/26 19:02:51 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;
	t_list	*curr;

	if (!lst)
		return (NULL);
	ret_lst = ft_lstnew(f(lst->content));
	if (!ret_lst)
		return (ret_lst);
	curr = ret_lst;
	while (lst->next)
	{
		curr->next = ft_lstnew(f(lst->next->content));
		if (!curr->next)
		{
			ft_lstclear(&ret_lst, del);
			return (NULL);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (ret_lst);
}
