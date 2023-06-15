/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:20:02 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 20:52:07 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_m_substr(char const *s, unsigned int start, int precision)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(str = malloc(sizeof(char) * (precision + 1))))
		return (0);
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
		return (0);
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
**Precision is by default 6, precision means the numbers after the comma
*/

char		*ft_ftoa(double f, int precision)
{
	long long int	ipart;
	int				i;
	long double		point_part;
	char			*str;
	char			*str2;

	if (precision == -1)
		precision = 6;
	ipart = (long long int)f;
	str = ft_mltoa(ipart);
	i = ft_strlen(str);
	str[i] = '.';
	str[i + 1] = '\0';
	point_part = f;
	point_part = point_part - ipart + 1;
	i = precision + 1;
	while (i--)
		point_part = point_part * 10.;
	str2 = ft_mltoa((long long int)point_part);
	str2 = ft_m_substr(str2, 1, precision + 1);
	str = ft_strjoin(str, str2);
	str = ft_last_decf(str);
	if (precision == 0)
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}
