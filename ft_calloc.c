/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:59:16 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 03:59:18 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	length;
	char	*mem;

	length = size * count;
	mem = (char *)malloc(length);
	if (!mem)
		return ((void *)0);
	i = 0;
	while (length--)
		*(mem + i++) = '\0';
	return (mem);
}
