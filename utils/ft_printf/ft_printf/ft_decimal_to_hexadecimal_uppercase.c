/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexadecimal_uppercase.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:18:54 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 20:58:51 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**Converts a decimal(10-base) into a hexadecimal(16-base),
**and puts the hexadecimal into a string, checks the precision
**flags and adds 0s in the string accordingly
*/

static int	ft_count_dec_to_hex(unsigned long i)
{
	int counter;

	counter = 0;
	while (i)
	{
		i = i / 16;
		counter++;
	}
	return (counter);
}

static void	ft_norm(int *r, unsigned long long int *s, int *i, char *t_r)
{
	*r = *s % 16;
	if (*r < 10)
		*r = *r + 48;
	else
		*r = *r + 55;
	t_r[*i] = *r;
	*i = *i + 1;
	*s = *s / 16;
}

char		*ft_decimal_to_hexadecimal_uppercase(unsigned long long int s)
{
	char	*hexadecimal;
	char	*temp_rev;
	int		i;
	int		l;
	int		remainder;

	i = 0;
	l = 0;
	remainder = 0;
	if (!(temp_rev = malloc(sizeof(char) * ft_count_dec_to_hex(s))))
		g_error = 1;
	if (!(hexadecimal = malloc(sizeof(char) * ft_count_dec_to_hex(s))))
		g_error = 1;
	while (s)
		ft_norm(&remainder, &s, &i, temp_rev);
	temp_rev[i] = '\0';
	while (i--)
	{
		hexadecimal[l] = temp_rev[i];
		l++;
	}
	free(temp_rev);
	hexadecimal[l] = '\0';
	return (hexadecimal);
}
