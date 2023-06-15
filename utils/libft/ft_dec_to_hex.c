/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexadecimal_lowercase.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:18:40 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 18:28:44 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Converts a decimal(10-base) into a hexadecimal(16-base),
**and puts the hexadecimal into a string,
**Prepends with zeros to have a minimal length of 8
**Initially comes from my ft_printf however modifs have been added
*/

static char *min_len(char *s)
{
	int len = ft_strlen(s);

	while (len < 8)
	{
		if (!(s = ft_strjoin_f("0", s, 2)))
			ft_malloc_error();
		len++;
	}
	return s;
}

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
		*r = *r + 87;
	t_r[*i] = *r;
	*i = *i + 1;
	*s = *s / 16;
}

char		*ft_dec_to_hex(unsigned long long int s)
{
	char	*hexadecimal;
	char	*temp_rev;
	// char *ret;
	int		i;
	int		l;
	int		remainder;

	i = 0;
	l = 0;
	remainder = 0;
	if (!(temp_rev = malloc(sizeof(char) * ft_count_dec_to_hex(s))))
		ft_malloc_error();
	if (!(hexadecimal = malloc(sizeof(char) * ft_count_dec_to_hex(s))))
		ft_malloc_error();
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
	return min_len(hexadecimal);
}
