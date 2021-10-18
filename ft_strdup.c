/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:02:31 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:02:34 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s_c;

	i = -1;
	s_c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s_c)
		return ((void *)0);
	while (*(s1 + ++i))
		*(s_c + i) = *(s1 + i);
	*(s_c + i) = '\0';
	return (s_c);
}
