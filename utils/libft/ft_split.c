/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:30:45 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/21 22:10:30 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnum(char a, char b)
{
	if (a == b)
		return (1);
	else
		return (0);
}

static int	ft_count(char const *s, char c)
{
	int		i;
	int		counter;
	int		new_str;

	i = 0;
	counter = 0;
	new_str = 1;
	while (s[i])
	{
		if (!(ft_isnum(s[i], c)) && new_str)
		{
			counter++;
			new_str = 0;
		}
		if (ft_isnum(s[i], c))
			new_str = 1;
		i++;
	}
	counter++;
	return (counter);
}

static char	*ft_next_substr(char const *s, char c, int *l)
{
	int	sub_str_start;
	int sub_str_size;

	while (s[*l] == c)
		*l = *l + 1;
	sub_str_start = *l;
	while (s[*l])
	{
		if (s[*l] == c)
			break ;
		*l = *l + 1;
	}
	sub_str_size = *l - sub_str_start;
	return (ft_substr(s, sub_str_start, sub_str_size));
}

void		ft_freesplit(char **str)
{
	int i;

	i = 0;
	free(str);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

char		**ft_split(char const *s, char c)
{
	int		counter;
	char	**str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (s == NULL)
		return (0);
	counter = ft_count(s, c);
	if (!(str = malloc(sizeof(char*) * (counter))))
		return (0);
	while (counter != 1)
	{
		str[i] = ft_next_substr(s, c, &l);
		if (!str[i])
		{
			ft_freesplit(str);
			return (str);
		}
		i++;
		counter--;
	}
	str[i] = 0;
	return (str);
}
