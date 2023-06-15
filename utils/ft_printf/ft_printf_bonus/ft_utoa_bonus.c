/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:25:05 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:34:45 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_lcounter(unsigned long long int n)
{
	unsigned int counter;

	counter = 0;
	while (n >= 10)
	{
		counter++;
		n = n / 10;
	}
	counter++;
	return (counter);
}

char		*ft_ultoa(unsigned long long int n)
{
	char			*str;
	unsigned int	counter;

	counter = ft_lcounter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_lcounter(n) + 1))))
		g_error = 1;
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
