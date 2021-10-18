/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:03:49 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:03:50 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return ((void *)0);
	if ((size_t)start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = (size_t)start;
	while (*(s + i) && i - (size_t)start + 1 < len)
		i++;
	subs = (char *)malloc(sizeof(char) * (i - (size_t)start + 2));
	if (!subs)
		return ((void *)0);
	*(subs + (i - (size_t)start + 1)) = '\0';
	while (i > (size_t)start)
	{
		*(subs + i - (size_t)start) = *(s + i);
		i--;
	}
	*(subs + i - (size_t)start) = *(s + i);
	return (subs);
}
