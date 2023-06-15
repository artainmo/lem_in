/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:28:48 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 22:21:39 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_modulo_f(va_list *arguments, int *ret_str_l, t_flags *fl)
{
	double	f;
	char	*s;
	int		witdh;
	double	tmp;

	f = va_arg(*arguments, double);
	tmp = f;
	if (f < 0)
	{
		*ret_str_l = *ret_str_l + 1;
		f = f * -1;
	}
	s = ft_ftoa(f, fl->precision);
	witdh = ft_strlen2(s);
	if (tmp < 0)
		witdh++;
	if (tmp < 0 && fl->flag_0)
		write(1, "-", 1);
	fl->minus_flag ? 0 : ft_min_witdh(fl->min_witdh, &witdh, ret_str_l, fl);
	if (tmp < 0 && !fl->flag_0)
		write(1, "-", 1);
	ft_m_h_putstr(s, ret_str_l);
	fl->minus_flag ? ft_min_witdh(fl->min_witdh, &witdh, ret_str_l, fl) : 0;
	free(s);
}
