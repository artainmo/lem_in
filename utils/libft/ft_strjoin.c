/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:52:28 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/17 23:21:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char const *s1, char *str, int *i)
{
	while (s1[*i])
	{
		str[*i] = s1[*i];
		*i = *i + 1;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_cat(s1, str, &i);
	while (s2[l])
	{
		str[i + l] = s2[l];
		l++;
	}
	str[i + l] = '\0';
	return (str);
}
