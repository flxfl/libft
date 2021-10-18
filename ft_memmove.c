/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:01:50 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:01:50 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*l1;
	char	*l2;

	if (!dst && !src)
		return ((void *)0);
	l1 = (char *)dst;
	l2 = (char *)src;
	if (l1 > l2)
	{
		i = n;
		while (i--)
			*(l1 + i) = *(l2 + i);
	}
	else
	{
		i = -1;
		while (++i < n)
			*(l1 + i) = *(l2 + i);
	}
	return (l1);
}
