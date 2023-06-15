/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:36:30 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:36:32 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	part2(const char *str)
{
	int		count;
	double	res2;

	count = 0;
	res2 = ft_abs(ft_atoi(str));
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	while (count > 0)
	{
		res2 /= 10;
		count--;
	}
	return (res2);
}

double			ft_atof(char *str)
{
	double	res;
	double	res1;
	int		count;
	int		neg;

	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	count = 0;
	res1 = ft_abs(ft_atoi(str));
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	if (!*str || *str != '.')
		return (neg * res1);
	str++;
	res = res1 + part2(str);
	return (neg * res);
}
