/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_no_insignificant.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:21:04 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:18:13 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_norm_g_no_insignificant(int *i, char *s, int *no)
{
	while (i)
	{
		if (s[*i] == '0')
			s[*i] = '\0';
		else if (s[*i] == '.')
		{
			s[*i] = '\0';
			*no = 1;
			break ;
		}
		else
			break ;
		*i = *i - 1;
	}
	return (s);
}

char	*ft_g_no_insignificant(char *s)
{
	int		i;
	int		no;
	char	*dup;

	i = ft_strlen2(s) - 1;
	no = 0;
	if (!(dup = ft_strdup(s)))
		return (0);
	s = ft_norm_g_no_insignificant(&i, s, &no);
	if (no)
		return (s);
	else
	{
		while (i)
		{
			if (s[i] == '.')
				return (s);
			i--;
		}
		return (dup);
	}
}

char	*ft_g_e_no_insignificant(char *s)
{
	int		i;
	char	*s2;

	i = ft_strlen2(s) - 5;
	s2 = s + i + 1;
	while (i)
	{
		if (s[i] == '0')
			s[i] = '\0';
		else if (s[i] == '.')
		{
			s[i] = '\0';
			break ;
		}
		else
			break ;
		i--;
	}
	if (!(s = ft_strjoin(s, s2)))
		return (0);
	return (s);
}
