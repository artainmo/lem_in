/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:46:51 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/14 17:17:38 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	while (i != 0)
	{
		i--;
		s--;
		if (*s == (char)c)
			return ((char*)s);
	}
	return (0);
}
