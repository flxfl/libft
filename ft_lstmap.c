/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:01:25 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:01:27 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return ((void *)0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return ((void *)0);
	new = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&new, del);
			return ((void *)0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	temp->next = (void *)0;
	return (new);
}
