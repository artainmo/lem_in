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

/*
** Searches the last occurence of the character c in the string s.
** Returns -1 if not found otherwise it
** returns the index in the string the last char occurence is at.
*/

int	ft_strrchr_m(char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
