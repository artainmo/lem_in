/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:33:21 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/09 23:38:32 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned char	*str;

	str = (unsigned char*)src;
	while (n != 0)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst++ = *(unsigned char*)src++;
			return (dst);
		}
		n--;
		str++;
	}
	return (0);
}
