/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:48:57 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/10 18:46:55 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, unsigned int l)
{
	unsigned int		h1;
	unsigned int		h2;
	unsigned int		n1;
	unsigned int		n2;

	h1 = 0;
	n1 = 0;
	if (!*n)
		return ((char *)h);
	while (*(h + h1) && h1 < l)
	{
		h2 = h1;
		n2 = n1;
		while (*(h + h2) == *(n + n2) && h1 + n2 < l && *(n + n2))
		{
			h2++;
			n2++;
		}
		if (*(n + n2) == '\0')
			return ((char *)(h + h1));
		h1++;
	}
	return (0);
}
