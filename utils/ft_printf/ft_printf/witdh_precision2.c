/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   witdh_precision2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:19:14 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 18:05:34 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_l_precision(int *witdh, int *ret_str_l, t_norm norm, long int *i)
{
	if (norm.s[0] == '-' && norm.precision > *witdh - 1)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		*witdh = *witdh - 1;
		*i = *i * -1;
	}
	norm.precision = norm.precision - *witdh;
	if (norm.precision > 0)
		*witdh = *witdh + norm.precision;
	while (norm.precision > 0)
	{
		write(1, "0", 1);
		norm.precision = norm.precision - 1;
		*ret_str_l = *ret_str_l + 1;
	}
}

void	ft_ll_prec(int *witdh, int *ret_str_l, t_norm norm, long long int *i)
{
	if (norm.s[0] && norm.precision > *witdh - 1)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		*witdh = *witdh - 1;
		*i = *i * -1;
	}
	norm.precision = norm.precision - *witdh;
	if (norm.precision > 0)
		*witdh = *witdh + norm.precision;
	while (norm.precision > 0)
	{
		write(1, "0", 1);
		norm.precision = norm.precision - 1;
		*ret_str_l = *ret_str_l + 1;
	}
}

void	ft_u_precision(int *witdh, int *ret_str_l, t_norm norm, int m)
{
	if (((m == '#' || m == 'H') && norm.s[0] != '0') || m == 'p')
	{
		if (m == 'H')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		*ret_str_l = *ret_str_l + 2;
		*witdh = *witdh - 2;
	}
	norm.precision = norm.precision - *witdh;
	while (norm.precision > 0)
	{
		write(1, "0", 1);
		norm.precision = norm.precision - 1;
		*ret_str_l = *ret_str_l + 1;
	}
}
