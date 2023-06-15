/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scientific_notation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:23:10 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/24 23:07:25 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_last_dec1(char *str, int *zero_counter, int i)
{
	if (str[i - 1] >= '5')
	{
		if (str[i - 2] == '9')
		{
			str[i - 3] = str[i - 3] + 1;
			str[i - 2] = '0';
			i--;
			str = ft_last_dec2s(str, &i);
			if (str[i - 4] == 58)
			{
				str[i - 4] = 49;
				*zero_counter = *zero_counter + 1;
			}
		}
		else
			str[i - 2] = str[i - 2] + 1;
	}
	return (str);
}

static char	*ft_last_dec0(char *str, int precision, int *zero_counter)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	i = i + precision + 3;
	str = ft_last_dec1(str, zero_counter, i);
	str[i - 1] = '\0';
	i = 0;
	i = ft_strlen2(str);
	while (i < precision + 2)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_scientific_notatian3(char *s, int precision, int zero_counter)
{
	char	*pow;
	int		i;
	int		tmp;

	i = 0;
	s = ft_set_point_p(s, &zero_counter, precision);
	s = ft_last_dec0(s, precision, &zero_counter);
	i = ft_strlen2(s);
	s[i++] = 'e';
	s[i++] = '+';
	s[i++] = '\0';
	pow = ft_itoa2(zero_counter);
	if (ft_strlen2(pow) == 1)
	{
		tmp = pow[0];
		pow[0] = '0';
		pow[1] = tmp;
		pow[2] = '\0';
	}
	s = ft_strjoin(s, pow);
	return (s);
}

char		*ft_scientific_notatian2(char *s, int precision, int z_c, int n_z_c)
{
	char	*pow;
	int		tmp;
	int		i;

	i = 0;
	n_z_c = ft_e_non_zero_counter(s);
	s = ft_set_point_n(s, z_c, n_z_c, precision);
	s = ft_last_dec0(s, precision, &z_c);
	i = ft_strlen2(s);
	s[i++] = 'e';
	s[i++] = '\0';
	z_c = z_c * -1;
	pow = ft_itoa2(z_c);
	if (ft_strlen2(pow) == 2)
	{
		tmp = pow[1];
		pow[1] = '0';
		pow[2] = tmp;
		pow[3] = '\0';
	}
	s = ft_strjoin(s, pow);
	return (s);
}

char		*ft_scientific_notatian(char *s, int precision)
{
	int z_c;
	int n_z_c;

	z_c = 0;
	n_z_c = 0;
	if (precision == -1)
		precision = 6;
	if ((z_c = ft_e_zero_counter(s)))
		return (ft_scientific_notatian2(s, precision, z_c, n_z_c));
	else
		return (ft_scientific_notatian3(s, precision, z_c));
}
