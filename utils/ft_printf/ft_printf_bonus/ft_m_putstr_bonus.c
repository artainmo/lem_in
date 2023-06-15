/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 01:49:24 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:21:16 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_m_putstr(char *str, int *ret_str_l, int precision)
{
	int i;

	i = 0;
	if (precision == -1)
		precision = ft_strlen2(str) + 1;
	while (str[i] && precision)
	{
		write(1, &str[i], 1);
		*ret_str_l = *ret_str_l + 1;
		i++;
		precision--;
	}
}

void	ft_m_w_putstr(wchar_t *str, int *ret_str_l, int precision)
{
	int i;

	i = 0;
	if (precision == -1)
		precision = ft_w_strlen(str) + 1;
	while (str[i] && precision)
	{
		write(1, &str[i], 1);
		*ret_str_l = *ret_str_l + 1;
		i++;
		precision--;
	}
}

void	ft_m_h_putstr(char *str, int *ret_str_l)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		*ret_str_l = *ret_str_l + 1;
		i++;
	}
}
