/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:58:15 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 03:58:17 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	j;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	j = -1;
	if (!dstsize)
		return (src_l);
	if (dstsize < dst_l)
		return (src_l + dstsize);
	while (++j < src_l && dst_l + j + 1 < dstsize)
		*(dst + dst_l + j) = *(src + j);
	*(dst + dst_l + j) = '\0';
	return (dst_l + src_l);
}
