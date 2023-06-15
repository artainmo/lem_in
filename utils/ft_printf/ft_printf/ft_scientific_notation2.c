/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scientific_notation2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:23:35 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:33:05 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_e_zero_counter(char *s)
{
	int i;
	int zero_counter;

	i = 0;
	zero_counter = 0;
	if (s[i] == '0')
	{
		while (s[i] == '0' || s[i] == '.')
		{
			if (s[i] == '0')
				zero_counter++;
			i++;
		}
		return (zero_counter);
	}
	return (0);
}

int		ft_e_non_zero_counter(char *s)
{
	int i;
	int non_zero_counter;

	i = 0;
	non_zero_counter = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '.')
		{
			non_zero_counter++;
			while (s[i++])
				non_zero_counter++;
			return (non_zero_counter);
		}
		i++;
	}
	return (0);
}

char	*ft_set_point_n(char *s, int zero_count, int non_zero_c, int precision)
{
	int		i;
	char	*str;

	i = 1;
	s = ft_substr2(s, zero_count + 1, non_zero_c);
	if (!(str = malloc(sizeof(char) * (precision + 6))))
		g_error = 1;
	str[0] = s[0];
	str[1] = '.';
	while (s[i])
	{
		str[i + 1] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*ft_set_point_p(char *s, int *zero_counter, int precision)
{
	int		i;
	char	*str;

	i = 1;
	s = ft_no_point_s(s, zero_counter);
	if (!(str = malloc(sizeof(char) * (precision + 6))))
		g_error = 1;
	str[0] = s[0];
	str[1] = '.';
	while (s[i])
	{
		str[i + 1] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*ft_last_dec2s(char *str, int *i)
{
	while (str[*i - 2] == 58)
	{
		if (str[*i - 3] != '.')
		{
			str[*i - 3] = str[*i - 3] + 1;
			str[*i - 2] = '0';
		}
		else
		{
			str[*i - 4] = str[*i - 4] + 1;
			str[*i - 2] = '0';
			break ;
		}
		*i = *i - 1;
	}
	return (str);
}
