/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:32:05 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/10 19:17:44 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char			*d;
	unsigned char	const	*s;

	d = dest;
	s = src;
	if (n == 0 || (!dest && !src))
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}
