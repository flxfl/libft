/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:58:20 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:08:41 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_c(char const *s, char c)
{
	int	i;
	int	count;
	int	has_started;

	i = 0;
	count = 0;
	has_started = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			if (has_started)
				count++;
			has_started = 0;
		}
		else
			has_started = 1;
		i++;
	}
	if (has_started)
		count++;
	return (count);
}

static int	*se1(char const *s, char c, int start)
{
	static int	se[2];

	se[0] = start;
	while (s[se[0]] == c && s[se[0]])
		se[0]++;
	se[1] = se[0];
	while (s[se[1]] != c && s[se[1]])
		se[1]++;
	return (se);
}

static void	*ft_free(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return ((void *)0);
}

static char	**ft_splitter(char const *s, char c, int word, int i)
{
	int		start;
	int		end;
	char	**str;

	str = (char **)malloc(sizeof(char *) * (word_c(s, c) + 1));
	if (!str)
		return ((void *)0);
	while (++word < word_c(s, c))
	{
		start = se1(s, c, i)[0];
		end = se1(s, c, i)[1];
		str[word] = ft_substr(s, start, end - start);
		if (!str[word])
			return (ft_free(str));
		i = se1(s, c, i)[1] + 1;
	}
	str[word] = (void *)0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return ((void *)0);
	if (word_c(s, c))
		return (ft_splitter(s, c, -1, 0));
	str = (char **)malloc(sizeof(char *));
	if (!str)
		return ((void *)0);
	*str = (void *)0;
	return (str);
}
