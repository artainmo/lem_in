/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:06:13 by artainmo          #+#    #+#             */
/*   Updated: 2020/02/23 18:08:19 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_f(char *str, int len)
{
	char	*ret;
	
	if (len < 1 || str == 0)
		return (0);
	if ((ret = ft_substr(str, len, ft_strlen(str))) == 0)
		return (0);
	free(str);
	return (ret);
}
