/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:10:20 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 20:10:36 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	check_plus_minus(char const *str, int *i, int *mc, int *c)
{
	if ((str[*i] == 43 || str[*i] == 45) && str[*i])
	{
		while ((str[*i] == 43 || str[*i] == 45) && str[*i])
		{
			if (str[*i] == 45)
				*mc = *mc + 1;
			*i = *i + 1;
			*c = *c + 1;
		}
	}
}

static void	check_digits(char const *str, int *i, long *res)
{
	if (str[*i] > 47 && str[*i] < 58 && str[*i])
	{
		while (str[*i] > 47 && str[*i] < 58 && str[*i])
		{
			*res = *res * 10 + (str[*i] - 48);
			*i = *i + 1;
		}
	}
}

int			ft_atoi(const char *str)
{
	int		i;
	int		mc;
	long	res;
	int		c;

	i = 0;
	res = 0;
	c = 0;
	mc = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	check_plus_minus(str, &i, &mc, &c);
	check_digits(str, &i, &res);
	if (!(mc % 2 == 0))
		res = res * -1;
	if (c > 1)
		return (0);
	if (res < 9223372036854775807 && res > 2147483647)
		return (0);
	else if (res > -9223372036854775807 && res < -2147483648)
		return (-1);
	else
		return (res);
}
