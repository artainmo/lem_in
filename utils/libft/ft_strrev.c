/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:20:49 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/07 11:40:13 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrev(char *str, int len)
{
  for (int i = 0; i < len/2; i++) {
    char straight = str[i];
    char reverse = str[len-i-1];
    str[i] = reverse;
    str[len-i-1] = straight;
	}
	return str;
}
