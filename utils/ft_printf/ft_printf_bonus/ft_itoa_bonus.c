/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 05:04:41 by artainmo          #+#    #+#             */
/*   Updated: 2020/03/01 05:05:00 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_counter(int n)
{
	int counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = n * -1;
	}
	while (n >= 10)
	{
		counter++;
		n = n / 10;
	}
	counter++;
	return (counter);
}

static void	ft_neg(int *n, char *str)
{
	*n = *n * -1;
	str[0] = '-';
}

char		*ft_itoa2(int n)
{
	char	*str;
	int		counter;

	counter = ft_counter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_counter(n) + 1))))
		g_error = 1;
	if (n == -2147483648)
	{
		if (!(str = ft_strdup("-2147483648")))
			return (0);
		return (str);
	}
	else if (n < 0)
		ft_neg(&n, str);
	str[counter + 1] = '\0';
	while (n >= 10)
	{
		str[counter] = n % 10 + 48;
		n = n / 10;
		counter--;
	}
	str[counter] = n % 10 + 48;
	return (str);
}

int			ft_lcounter(long long int n)
{
	unsigned int counter;

	counter = 0;
	if (n < 0)
	{
		n = n * -1;
		counter++;
	}
	while (n >= 10)
	{
		counter++;
		n = n / 10;
	}
	counter++;
	return (counter);
}

char		*ft_ltoa(long long int n)
{
	char	*str;
	int		counter;

	counter = ft_lcounter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_lcounter(n) + 2))))
		g_error = 1;
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[counter + 1] = '\0';
	while (n >= 10)
	{
		str[counter] = n % 10 + 48;
		n = n / 10;
		counter--;
	}
	str[counter] = n % 10 + 48;
	return (str);
}
