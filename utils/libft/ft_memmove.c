/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:35:09 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/14 17:14:01 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char			*s;
	char			*d;
	unsigned int	i;

	i = 0;
	s = (char*)src;
	d = (char*)dst;
	if (len == 0 || (!dst && !src))
		return (dst);
	if (s < d)
	{
		while (len-- != '\0')
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
