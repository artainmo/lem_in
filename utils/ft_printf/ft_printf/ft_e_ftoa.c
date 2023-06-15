/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:19:06 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 20:50:51 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_me_substr(char const *s, unsigned int start, int precision)
{
	char			*str;
	int				i;

	i = 0;
	if (!s)
		return (0);
	if (!(str = malloc(sizeof(char) * (precision + 1))))
		g_error = 1;
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

static int	ft_mlcounter(long long int n)
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

	counter = ft_mlcounter(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_mlcounter(n) + 2))))
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

static int	ft_find_precision(double f)
{
	long long int	ipart;
	long double		point_part;
	char			*str2;
	int				i;

	i = 0;
	ipart = (long long int)f;
	point_part = f;
	point_part = point_part - ipart + 1;
	point_part = point_part * 1000000000000000;
	str2 = ft_mltoa((long long int)point_part);
	i = ft_strlen2(str2) - 1;
	while (str2[i] == '0' || str2[i] == '.')
	{
		str2[i] = '\0';
		i--;
	}
	i = ft_strlen2(str2) - 1;
	if (i < 6)
		return (6);
	return (i);
}

/*
** This function doesn't has a default precision of 6, but it
** returns the whole number
** without the insignificant 0s at the end unless if the precision asks for it.
*/

char		*ft_e_ftoa(double f, int precision)
{
	long long int	ipart;
	int				i;
	long double		point_part;
	char			*str;
	char			*str2;

	point_part = 0;
	precision = ft_find_precision(f);
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
	str2 = ft_me_substr(str2, 1, precision + 1);
	str = ft_strjoin(str, str2);
	str = ft_last_dece(str);
	return (str);
}
