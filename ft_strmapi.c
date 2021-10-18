/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:03:19 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:03:22 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(char const *s, char (*f)(unsigned int, char))
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (*(s + ++i))
	{
		if (f(i, *(s + i)))
			len++;
	}
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*line;
	int		i;
	int		index;

	if (!s)
		return ((void *)0);
	line = (char *)malloc(sizeof(char) * (ft_length(s, f) + 1));
	if (!line)
		return ((void *)0);
	i = -1;
	index = -1;
	while (*(s + ++i))
		if (f(i, *(s + i)))
			*(line + ++index) = f(i, *(s + i));
	line[index + 1] = '\0';
	return (line);
}
