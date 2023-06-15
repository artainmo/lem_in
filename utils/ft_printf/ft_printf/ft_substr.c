/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 05:00:47 by artainmo          #+#    #+#             */
/*   Updated: 2020/03/01 05:01:04 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	unsigned int	ft_ustrlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_substr2(char *s, unsigned int st, unsigned int len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_ustrlen(s) < st)
		len = 0;
	else if (st + len > ft_ustrlen(s))
		len = ft_ustrlen(s) - st;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		g_error = 1;
	while (i < len)
	{
		str[i] = s[st + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
