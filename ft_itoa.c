/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlkshk <smlkshk@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 04:00:28 by smlkshk           #+#    #+#             */
/*   Updated: 2021/10/17 04:00:30 by smlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_save(void)
{
	char	*num;

	num = (char *)malloc(12 * sizeof(char));
	if (!num)
		return ((void *)0);
	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	num[11] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		saver;

	if (n == -2147483648)
		return (ft_save());
	saver = ft_len(n);
	i = 0;
	num = (char *)ft_calloc(saver + 1, sizeof(char));
	if (!num)
		return ((void *)0);
	*(num + saver) = '\0';
	*(num) = '0';
	if (n < 0)
	{
		*num = '-';
		n *= -1;
	}
	while (n > 0)
	{
		*(num + saver - ++i) = n % 10 + '0';
		n /= 10;
	}
	return (num);
}
