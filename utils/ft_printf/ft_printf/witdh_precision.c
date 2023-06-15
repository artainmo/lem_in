/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   witdh_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:18:17 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:18:25 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_min_witdh_s(int min_witdh, int *witdh, int *ret_str_l, t_flags *flag)
{
	min_witdh = min_witdh - *witdh;
	while (min_witdh > 0)
	{
		if (!flag->flag_0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		min_witdh--;
		*ret_str_l = *ret_str_l + 1;
		*witdh = *witdh + 1;
	}
}

void	ft_min_witdh(int min_witdh, int *witdh, int *ret_str_l, t_flags *flag)
{
	if (flag->precision == -1 || flag->precision <= *witdh)
		min_witdh = min_witdh - *witdh;
	else if (flag->precision > *witdh)
		min_witdh = min_witdh - flag->precision;
	while (min_witdh > 0)
	{
		if (!flag->flag_0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		min_witdh--;
		*ret_str_l = *ret_str_l + 1;
	}
}

void	ft_int_precision(int *witdh, int *ret_str_l, t_norm norm, int *i)
{
	if (norm.s[0] == '-' && norm.precision > *witdh - 1)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		*witdh = *witdh - 1;
		*i = *i * -1;
	}
	norm.precision = norm.precision - *witdh;
	while (norm.precision > 0)
	{
		write(1, "0", 1);
		norm.precision = norm.precision - 1;
		*ret_str_l = *ret_str_l + 1;
	}
}

void	ft_ch_precision(int *witdh, int *ret_str_l, t_norm norm, char *i)
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

void	ft_sh_precision(int *witdh, int *ret_str_l, t_norm norm, short int *i)
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
