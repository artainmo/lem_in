/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:30:59 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 18:08:01 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u3_writ(t_flags *flags, int *ret_str_l, va_list *arguments, char m)
{
	int						witdh;
	unsigned long long int	u;
	char					*s;
	t_norm					norm;

	u = va_arg(*arguments, unsigned long long int);
	s = ft_ultoa(u);
	witdh = ft_strlen2(s);
	if (u == 0 && flags->precision == 0)
		flags->min_witdh++;
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	if (flags->precision != 0 || u != 0)
		ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void	ft_u4_writ(t_flags *flags, int *ret_str_l, va_list *arguments, char m)
{
	int					witdh;
	unsigned long int	u;
	char				*s;
	t_norm				norm;

	u = va_arg(*arguments, unsigned long int);
	s = ft_ultoa(u);
	witdh = ft_strlen2(s);
	if (u == 0 && flags->precision == 0)
		flags->min_witdh++;
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	if (flags->precision != 0 || u != 0)
		ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void	ft_u5_writ(t_flags *flags, int *ret_str_l, va_list *arguments, char m)
{
	int				witdh;
	unsigned int	u;
	char			*s;
	t_norm			norm;

	u = va_arg(*arguments, unsigned int);
	s = ft_ultoa(u);
	witdh = ft_strlen2(s);
	if (u == 0 && flags->precision == 0)
		flags->min_witdh++;
	norm.s = s;
	norm.precision = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_u_precision(&witdh, ret_str_l, norm, m);
	if (flags->precision != 0 || u != 0)
		ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void	ft_modulo_u(char m, va_list *arguments, int *ret_str_l, t_flags *flags)
{
	if (flags->chars)
		ft_u_writ(flags, ret_str_l, arguments, m);
	else if (flags->shorts)
		ft_u2_writ(flags, ret_str_l, arguments, m);
	else if (flags->long_long)
		ft_u3_writ(flags, ret_str_l, arguments, m);
	else if (flags->longs)
		ft_u4_writ(flags, ret_str_l, arguments, m);
	else
		ft_u5_writ(flags, ret_str_l, arguments, m);
}
