/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_ftoa2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:19:18 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/30 20:28:11 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_norm_set_point_back(int *point, char *s)
{
	int		i;
	char	*s2;

	i = 0;
	*point = 1;
	if (!(s2 = malloc(sizeof(char) * (ft_strlen2(s) + 1))))
		g_error = 1;
	while (s[i])
	{
		s2[0] = 49;
		s2[i + 1] = s[i];
		i++;
	}
	s2[i + 1] = '\0';
	free(s);
	return (s2);
}

static char	*ft_set_point_back(char *str, int *point)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = malloc((sizeof(char) * (ft_strlen2(str) + 1)))))
		g_error = 1;
	while (*point)
	{
		s[i] = str[i];
		i++;
		*point = *point - 1;
	}
	s[i] = '.';
	while (str[i])
	{
		s[i + 1] = str[i];
		i++;
	}
	s[i + 1] = '\0';
	i = 0;
	free(str);
	if (s[0] == '0')
		return (ft_norm_set_point_back(point, s));
	return (s);
}

static char	*ft_last_dec2(char *str, int i, int l, int point)
{
	i = ft_strlen2(str);
	if (str[i - 1] >= '5')
	{
		if (str[i - 2] == '9')
		{
			l = i;
			str = ft_no_point_e(str, &point);
			str[i - 3] = str[i - 3] + 1;
			str[i - 2] = '0';
			l--;
			while (str[l - 2] == 58)
			{
				str[l - 3] = str[l - 3] + 1;
				str[l - 2] = '0';
				l--;
			}
			str = ft_set_point_back(str, &point);
			if (point)
				i++;
		}
		else
			str[i - 2] = str[i - 2] + 1;
	}
	str[i - 1] = '\0';
	return (str);
}

char		*ft_last_dece(char *str)
{
	int i;
	int l;
	int point;

	i = 0;
	l = 0;
	point = 0;
	return (ft_last_dec2(str, i, l, point));
}

char		*ft_zero_zero(char *str, int precision)
{
	int i;

	i = 0;
	if (precision == -1)
		precision = 6;
	str[i++] = '0';
	if (precision > 0)
	{
		str[i++] = '.';
		while (precision)
		{
			str[i++] = '0';
			precision--;
		}
		precision = 1;
	}
	str[i++] = 'e';
	str[i++] = '+';
	str[i++] = '0';
	str[i++] = '0';
	str[i++] = '\0';
	return (str);
}
