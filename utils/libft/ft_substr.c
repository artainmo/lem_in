/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:10:16 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/21 21:39:15 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ustrlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_ustrlen(s) < start)
		len = 0;
	else if (start + len > ft_ustrlen(s))
		len = ft_ustrlen(s) - start;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
