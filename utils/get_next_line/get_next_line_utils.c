/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:27:41 by artainmo          #+#    #+#             */
/*   Updated: 2019/12/17 02:17:45 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_m(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_m(char *s1, char *buf)
{
	char	*ret;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s1 && s1[i])
		i++;
	while (buf[l] && buf[l] != '\n')
		l++;
	if (!(ret = malloc(i + l + 1)))
		return (0);
	i = 0;
	l = 0;
	while (s1 && s1[l])
		ret[i++] = s1[l++];
	l = 0;
	while (buf[l] && buf[l] != '\n')
		ret[i++] = buf[l++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}
