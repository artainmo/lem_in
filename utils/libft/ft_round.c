/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:32:23 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:35:12 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ftoi2(char *s, int i, int l)
{
	s[i - 1] = '\0';
	while (s[i - 2] == '9' && i)
		i--;
	i--;
	if (i == 0 && s[i] == '9')
	{
		s[i] = '1';
		i++;
		s[l - 1] = '0';
		s[l] = '\0';
	}
	else
		s[i - 1] = s[i - 1] + 1;
	while (s[i])
	{
		s[i] = '0';
		i++;
	}
	return (s);
}

static int	ft_ftoi(char *s)
{
	int i;
	int l;

	i = ft_strlen(s) - 1;
	l = i;
	if (s[i] >= '5')
	{
		if (s[i - 2] != '9')
			s[i - 2] = s[i - 2] + 1;
		else
			s = ft_ftoi2(s, i, l);
		return (ft_atoi(s));
	}
	else
	{
		s[i - 1] = '\0';
		return (ft_atoi(s));
	}
}

int			ft_round(double d)
{
	int		i;
	char	*s;

	s = ft_ftoa(d, 1);
	i = ft_ftoi(s);
	return (i);
}

int ft_round_up(float x)
{
    int res;

    if (x >= 0.0) {
        res = ft_round(x + 0.5);
    } else {
        res = ft_round(x - 0.5);
    }
    return res;
}
