/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:04:07 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/17 22:50:47 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa(int n)
{
	char	*str;
	int		counter;

	counter = ft_counter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_counter(n) + 1))))
		return (0);
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
