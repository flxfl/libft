/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:03:40 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:03:43 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_l(const char *s, const char *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (*(s + i))
	{
		j = 0;
		if (found)
			found--;
		while (*(set + j) && !found)
		{
			if (*(set + j) == *(s + i))
				found++;
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_trim_r(const char *s, const char *set)
{
	int	i;
	int	j;
	int	found;

	i = (int)ft_strlen(s) - 1;
	found = 0;
	while (i >= 0)
	{
		j = 0;
		if (found)
			found--;
		while (*(set + j) && !found)
		{
			if (*(set + j) == *(s + i))
				found++;
			j++;
		}
		if (!found)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	return (ft_substr(s1, ft_trim_l(s1, set), ft_trim_r(s1, set) - \
			ft_trim_l(s1, set) + 1));
}
