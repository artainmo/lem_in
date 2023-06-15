/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_i2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:29:38 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:13:53 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_i_writ(char **s, t_flags *f, int *ret_str_l, va_list *arguments)
{
	int		witdh;
	char	i;
	t_norm	norm;

	i = va_arg(*arguments, int);
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
		ft_ch_precision(&witdh, ret_str_l, norm, &i);
	if (i != 0 || f->precision != 0)
		ft_m_h_putstr(*s, ret_str_l);
	f->minus_flag ? ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f) : 0;
}

void	ft_i2_writ(char **s, t_flags *f, int *ret_str_l, va_list *arguments)
{
	int			witdh;
	short int	i;
	t_norm		norm;

	i = va_arg(*arguments, int);
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
		ft_sh_precision(&witdh, ret_str_l, norm, &i);
	if (i != 0 || f->precision != 0)
		ft_m_h_putstr(*s, ret_str_l);
	f->minus_flag ? ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f) : 0;
}
