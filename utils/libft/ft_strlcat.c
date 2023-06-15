/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:57:51 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/14 17:15:52 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int l;
	unsigned int k;
	unsigned int m;
	unsigned int i;

	l = 0;
	k = 0;
	m = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[k])
		k++;
	while (dest[m] && m < size)
		m++;
	while (m + l + 1 < size && src[l])
	{
		dest[m + l] = src[l];
		l++;
	}
	if (i < size)
		dest[m + l] = '\0';
	return (m + k);
}
