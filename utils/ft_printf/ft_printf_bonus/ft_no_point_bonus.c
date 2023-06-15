/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:22:26 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:23:19 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_no_point_e(char *s, int *point)
{
	char	*s1;
	char	*s2;

	*point = 0;
	s1 = s;
	while (*s != '.')
	{
		s++;
		*point = *point + 1;
	}
	*s = '\0';
	s++;
	s2 = s;
	s = ft_strjoin(s1, s2);
	return (s);
}

char	*ft_no_point_f(char *s, int *point)
{
	char	*s1;
	char	*s2;

	*point = 0;
	s1 = s;
	while (*s != '.')
	{
		s++;
		*point = *point + 1;
	}
	*s = '\0';
	s++;
	s2 = s;
	s = ft_strjoin(s1, s2);
	return (s);
}

char	*ft_no_point_s(char *s, int *zero_counter)
{
	char	*s1;
	char	*s2;

	*zero_counter = -1;
	s1 = s;
	while (*s != '.')
	{
		s++;
		*zero_counter = *zero_counter + 1;
	}
	*s = '\0';
	s++;
	s2 = s;
	s = ft_strjoin(s1, s2);
	return (s);
}

char	*ft_no_point_g(char *s, int *point)
{
	char	*s1;
	char	*s2;

	*point = 0;
	s1 = s;
	while (*s != '.')
	{
		s++;
		*point = *point + 1;
	}
	*s = '\0';
	s++;
	s2 = s;
	s = ft_strjoin(s1, s2);
	return (s);
}
