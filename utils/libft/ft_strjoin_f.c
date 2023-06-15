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

char		*ft_strjoin_f(char *s1, char *s2, int free_)
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
		return (s1);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_cat(s1, str, &i);
	while (s2[l])
	{
		str[i + l] = s2[l];
		l++;
	}
	str[i + l] = '\0';
	if (free_ == 3) {
		free(s1);
		free(s2);
	} else if (free_ == 1) {
		free(s1);
	} else if (free_ == 2) {
		free(s2);
	}
	return (str);
}

char *ft_strjoin_len_f(char *s1, int len1, char *s2, int len2, int free_)
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
		return (s1);
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (l < len2)
	{
		str[i + l] = s2[l];
		l++;
	}
	str[i + l] = '\0';
	if (free_ == 3) {
		free(s1);
		free(s2);
	} else if (free_ == 1) {
		free(s1);
	} else if (free_ == 2) {
		free(s2);
	}
	return (str);
}
