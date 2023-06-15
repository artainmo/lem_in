/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_u2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:31:15 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:15:23 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u_writ(t_flags *flags, int *ret_str_l, va_list *arguments, char m)
{
	int				witdh;
	unsigned char	u;
	char			*s;
	t_norm			norm;

	u = va_arg(*arguments, int);
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

void	ft_u2_writ(t_flags *flags, int *ret_str_l, va_list *arguments, char m)
{
	int					witdh;
	unsigned short int	u;
	char				*s;
	t_norm				norm;

	u = va_arg(*arguments, int);
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
