/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:20:29 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 20:53:52 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_m_substr(char const *s, unsigned int start, int precision)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (precision < 0)
		return (0);
	if (!(str = malloc(sizeof(char) * (precision + 1))))
	{
		g_error = 1;
		return (0);
	}
	while (i < precision && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	while (i < precision)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_counter(long long int n)
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

static char	*ft_mltoa(long long int n)
{
	char	*str;
	int		counter;

	counter = ft_counter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_counter(n) + 2))))
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

/*
**Precision is by default 6, precision means the total number
**of significant numbers before and after the comma
*/

static int	ft_norm_g(char **str2, char **str, int precision)
{
	int i;

	i = 0;
	if (*str[0] != '0')
		*str2 = ft_m_substr(*str2, 1, precision + 1 - ft_strlen2(*str) + 1);
	else
	{
		i = ft_count_b_zeros(*str2);
		*str2 = ft_m_substr(*str2, 1, precision + 1 - ft_strlen2(*str) + 2 + i);
	}
	return (i);
}

char		*ft_g_ftoa(double f, int precision)
{
	long long int	ipart;
	int				i;
	long double		point_part;
	char			*str;
	char			*str2;

	point_part = 0;
	if (precision == -1)
		precision = 6;
	ipart = (long long int)f;
	str = ft_mltoa(ipart);
	i = ft_strlen2(str);
	str[i] = '.';
	str[i + 1] = '\0';
	point_part = f;
	point_part = point_part - ipart + 1;
	i = precision + 1;
	while (i--)
		point_part = point_part * 10.;
	str2 = ft_ltoa((long long int)point_part);
	i = ft_norm_g(&str2, &str, precision);
	str = ft_strjoin(str, str2);
	str = ft_last_decg(str);
	return (str);
}
