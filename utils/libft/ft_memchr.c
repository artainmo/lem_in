/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:04:12 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/07 16:26:11 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n != 0)
	{
		n--;
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
