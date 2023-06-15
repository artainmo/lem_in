/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:30:32 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 20:55:36 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_s_writ(t_flags *flags, int *ret_str_l, va_list *arguments)
{
	int		witdh;
	char	*s;

	s = va_arg(*arguments, char *);
	if (!s)
		s = "(null)";
	if (flags->precision == -1 || flags->precision > ft_strlen2(s))
		witdh = ft_strlen2(s);
	else
		witdh = flags->precision;
	if (!flags->minus_flag)
		ft_min_witdh_s(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_m_putstr(s, ret_str_l, flags->precision);
	if (flags->minus_flag)
		ft_min_witdh_s(flags->min_witdh, &witdh, ret_str_l, flags);
}

void	ft_modulo_s(va_list *arguments, int *ret_str_l, t_flags *flags)
{
	wchar_t	*sw;
	int		witdh;

	if (flags->longs)
	{
		sw = va_arg(*arguments, wchar_t *);
		if (flags->precision == -1)
			witdh = ft_w_strlen(sw);
		else
			witdh = flags->precision;
		if (!flags->minus_flag)
			ft_min_witdh_s(flags->min_witdh, &witdh, ret_str_l, flags);
		ft_m_w_putstr(sw, ret_str_l, flags->precision);
		if (flags->minus_flag)
			ft_min_witdh_s(flags->min_witdh, &witdh, ret_str_l, flags);
	}
	else
		ft_s_writ(flags, ret_str_l, arguments);
}
