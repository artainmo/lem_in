/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:28:30 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/30 20:38:30 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_prec_zero(char *s, double f, t_flags *flags)
{
	if (flags->precision == 0 && f != 0.0)
	{
		s[1] = s[2];
		s[2] = s[3];
		s[3] = s[4];
		s[4] = s[5];
		s[5] = s[6];
	}
	return (s);
}

static void	ft_minus_e(double tmp, int *witdh, t_flags *flags, char *s)
{
	*witdh = ft_strlen2(s);
	if (tmp < 0)
		*witdh = *witdh + 1;
	if (tmp < 0 && flags->flag_0)
		write(1, "-", 1);
}

void		ft_modulo_e(va_list *arguments, int *ret_str_l, t_flags *fl)
{
	double	f;
	double	tmp;
	char	*s;
	int		witdh;

	f = va_arg(*arguments, double);
	tmp = f;
	if (f < 0)
	{
		*ret_str_l = *ret_str_l + 1;
		f = f * -1;
	}
	s = ft_e_ftoa(f, fl->precision);
	s = ft_scientific_notatian(s, fl->precision);
	if (f == 0.0)
		s = ft_zero_zero(s, fl->precision);
	s = ft_prec_zero(s, f, fl);
	ft_minus_e(tmp, &witdh, fl, s);
	!fl->minus_flag ? ft_min_witdh(fl->min_witdh, &witdh, ret_str_l, fl) : 0;
	if (tmp < 0 && !fl->flag_0)
		write(1, "-", 1);
	ft_m_h_putstr(s, ret_str_l);
	fl->minus_flag ? ft_min_witdh(fl->min_witdh, &witdh, ret_str_l, fl) : 0;
	free(s);
}
