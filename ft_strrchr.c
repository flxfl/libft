/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:03:35 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:03:37 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			str = (char *)(s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		str = (char *)(s + i);
	return (str);
}
