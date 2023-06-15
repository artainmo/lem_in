/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:58:02 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/08 16:11:38 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	ft_str_isdigit(char *str)
{
	int i;

	i = 0;
	if (str == 0)
		return (1);
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]) && (str[i] != '-' || ft_strlen(str) == 1))
			return (0);
		i++;
	}
	return (1);
}
