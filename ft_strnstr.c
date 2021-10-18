/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:03:31 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:03:34 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	i = -1;
	len_n = ft_strlen(needle);
	if (len_n == 0 || haystack == needle)
		return ((char *)haystack);
	while (++i < len && *(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) && *(needle + j) && \
			*(haystack + i + j) == *(needle + j) && i + j < len)
		{
			j++;
		}
		if (j == len_n)
			return ((char *)haystack + i);
	}
	return ((void *)0);
}
