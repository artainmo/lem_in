/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:29:22 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 18:09:46 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_i3_writ(char **s, t_flags *f, int *ret_str_l, va_list *a)
{
	int				witdh;
	long long int	i;
	t_norm			norm;

	i = va_arg(*a, long long int);
	*s = ft_ltoa(i);
	witdh = ft_strlen2(*s);
	if (*s[0] == '-' && f->precision >= witdh)
		f->min_witdh--;
	if (i == 0 && f->precision == 0)
		f->min_witdh++;
	if (*s[0] == '-' && !f->minus_flag && f->precision == -1 && f->flag_0)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		i = i * -1;
	}
	norm.s = *s;
	norm.precision = f->precision;
	f->minus_flag ? 0 : ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f);
	if (f->precision != -1)
		ft_ll_prec(&witdh, ret_str_l, norm, &i);
	if (i != 0 || f->precision != 0)
		ft_m_h_putstr(*s, ret_str_l);
	f->minus_flag ? ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f) : 0;
}

void	ft_i4_writ(char **s, t_flags *f, int *ret_str_l, va_list *a)
{
	int			witdh;
	long int	i;
	t_norm		norm;

	i = va_arg(*a, long int);
	*s = ft_ltoa(i);
	witdh = ft_strlen2(*s);
	if (*s[0] == '-' && f->precision >= witdh)
		f->min_witdh--;
	if (i == 0 && f->precision == 0)
		f->min_witdh++;
	if (*s[0] == '-' && !f->minus_flag && f->precision == -1 && f->flag_0)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		i = i * -1;
	}
	norm.s = *s;
	norm.precision = f->precision;
	f->minus_flag ? 0 : ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f);
	if (f->precision != -1)
		ft_l_precision(&witdh, ret_str_l, norm, &i);
	if (i != 0 || f->precision != 0)
		ft_m_h_putstr(*s, ret_str_l);
	f->minus_flag ? ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f) : 0;
}

void	ft_i5_writ(char **s, t_flags *f, int *ret_str_l, va_list *a)
{
	int		witdh;
	int		i;
	t_norm	norm;

	i = va_arg(*a, int);
	*s = ft_itoa2(i);
	witdh = ft_strlen2(*s);
	if (*s[0] == '-' && f->precision >= witdh)
		f->min_witdh--;
	if (i == 0 && f->precision == 0)
		f->min_witdh++;
	if (*s[0] == '-' && !f->minus_flag && f->precision == -1 && f->flag_0)
	{
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
		i = i * -1;
	}
	norm.s = *s;
	norm.precision = f->precision;
	f->minus_flag ? 0 : ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f);
	if (f->precision != -1)
		ft_int_precision(&witdh, ret_str_l, norm, &i);
	if (i != 0 || f->precision != 0)
		ft_m_putnbr(i, ret_str_l);
	f->minus_flag ? ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f) : 0;
}

void	ft_modulo_i(va_list *a, int *ret_str_l, t_flags *f)
{
	char *s;

	s = NULL;
	if (f->chars)
		ft_i_writ(&s, f, ret_str_l, a);
	else if (f->shorts)
		ft_i2_writ(&s, f, ret_str_l, a);
	else if (f->long_long)
		ft_i3_writ(&s, f, ret_str_l, a);
	else if (f->longs)
		ft_i4_writ(&s, f, ret_str_l, a);
	else
		ft_i5_writ(&s, f, ret_str_l, a);
	if (s)
		free(s);
}
