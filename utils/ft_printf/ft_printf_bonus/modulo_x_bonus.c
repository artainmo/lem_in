/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:31:33 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:15:48 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_x3_writ(char m, t_flags *flags, int *ret_str_l, va_list *a)
{
	unsigned long long int	u;
	char					*s;
	int						witdh;
	t_norm					norm;

	u = va_arg(*a, unsigned long long int);
	if (u == 0 && flags->precision != 0)
		s = "0";
	else
		s = ft_dec_to_hex_lowercase(u);
	witdh = ft_strlen2(s);
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (u != 0)
		free(s);
}

void	ft_x4_writ(char m, t_flags *flags, int *ret_str_l, va_list *a)
{
	unsigned long int	u;
	char				*s;
	int					witdh;
	t_norm				norm;

	u = va_arg(*a, unsigned long int);
	if (u == 0 && flags->precision != 0)
		s = "0";
	else
		s = ft_dec_to_hex_lowercase(u);
	witdh = ft_strlen2(s);
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (u != 0)
		free(s);
}

void	ft_x5_writ(char m, t_flags *flags, int *ret_str_l, va_list *a)
{
	unsigned int	u;
	char			*s;
	int				witdh;
	t_norm			norm;

	u = va_arg(*a, unsigned int);
	if (u == 0 && flags->precision != 0)
		s = "0";
	else
		s = ft_dec_to_hex_lowercase(u);
	witdh = ft_strlen2(s);
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (u != 0)
		free(s);
}

void	ft_modulo_x(char m, va_list *a, int *ret_str_l, t_flags *flags)
{
	if (flags->chars)
		ft_x_writ(m, flags, ret_str_l, a);
	else if (flags->shorts)
		ft_x2_writ(m, flags, ret_str_l, a);
	else if (flags->long_long)
		ft_x3_writ(m, flags, ret_str_l, a);
	else if (flags->longs)
		ft_x4_writ(m, flags, ret_str_l, a);
	else
		ft_x5_writ(m, flags, ret_str_l, a);
}
