/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:58:34 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 03:59:00 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\r' || c == '\t' || c == '\n' || \
		c == '\f' || c == ' ')
		return (1);
	return (0);
}

static int	ft_saver(const char *s, int i, int num, int sign)
{
	if (*(s + i + 1))
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	if (num * 10 + (*(s + i) - '0') == 2147483647)
		return (sign * (num * 10 + (*(s + i++) - '0')));
	if (num * 10 + (*(s + i++) - '0') > -2147483648 && sign < 0)
		return (0);
	if (*(s + i) == '8' && sign)
		return (-1);
	return (-2147483648);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(*(s + i)))
		i++;
	if (*(s + i) == '-')
	{
		sign = -1;
		i++;
	}
	if (*(s + i) == '+' && sign > 0)
		i++;
	while ('0' <= *(s + i) && *(s + i) <= '9')
	{
		if (num >= 214748364)
			return (ft_saver(s, i, num, sign));
		num = num * 10 + (*(s + i++) - '0');
	}
	return (sign * num);
}
