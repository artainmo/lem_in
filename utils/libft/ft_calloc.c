/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:03:16 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/14 18:14:30 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	char			*str;
	unsigned int	chars;

	chars = size * count / sizeof(char);
	if (!(str = malloc(size * count)))
		return (0);
	while (chars != 0)
	{
		str[chars] = '\0';
		chars--;
	}
	str[chars] = '\0';
	return (str);
}
