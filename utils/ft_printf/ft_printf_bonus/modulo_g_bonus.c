/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:29:03 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 20:54:59 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_min_witdh_g(int min_witdh, int *witdh, int *ret_str_l, t_flags *flag)
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
	}
}

void	ft_g_writ(t_flags *flags, char *s, int *ret_str_l, int witdh)
{
	if (flags->negative < 0 && flags->flag_0)
		write(1, "-", 1);
	if (!flags->minus_flag)
		ft_min_witdh_g(flags->min_witdh, &witdh, ret_str_l, flags);
	if (flags->negative < 0 && !flags->flag_0)
		write(1, "-", 1);
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh_g(flags->min_witdh, &witdh, ret_str_l, flags);
}

void	ft_modulo_g_neg(double *f, int *ret_str_l)
{
	if (*f < 0)
	{
		*ret_str_l = *ret_str_l + 1;
		*f = *f * -1;
	}
}

void	ft_mod_g1(va_list *arguments, int *ret_str_l, t_flags *flags, double f)
{
	char	*s;
	char	*s1;
	int		witdh;
	int		witdh1;

	f = va_arg(*arguments, double);
	flags->negative = f;
	ft_modulo_g_neg(&f, ret_str_l);
	s = ft_g_ftoa(f, flags->precision);
	s = ft_g_no_insignificant(s);
	witdh = ft_strlen2(s);
	if (flags->negative < 0)
		witdh++;
	s1 = ft_e_ftoa(f, flags->precision);
	s1 = ft_scientific_notatian(s1, flags->precision);
	s1 = ft_g_e_no_insignificant(s1);
	witdh1 = ft_strlen2(s1);
	if (flags->negative < 0)
		witdh1++;
	if (witdh <= witdh1)
		ft_g_writ(flags, s, ret_str_l, witdh);
	else
		ft_g_writ(flags, s1, ret_str_l, witdh1);
	free(s);
	free(s1);
}

void	ft_modulo_g(va_list *arguments, int *ret_str_l, t_flags *flags)
{
	double f;

	f = 0.0;
	ft_mod_g1(arguments, ret_str_l, flags, f);
}
