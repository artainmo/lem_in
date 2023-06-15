/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_+.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:26:45 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:14:26 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_plus_writ(char *s, t_flags *flags, int *ret_str_l, int i)
{
	int		witdh;
	t_norm	norm;

	witdh = ft_strlen2(s);
	witdh++;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	write(1, "+", 1);
	norm.s = s;
	norm.precision = flags->precision;
	ft_int_precision(&witdh, ret_str_l, norm, &i);
	*ret_str_l = *ret_str_l + 1;
	ft_m_putnbr(i, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

static void	ft_plus2_writ(char *s, t_flags *flags, int *ret_str_l, int i)
{
	int		witdh;
	t_norm	norm;

	witdh = ft_strlen2(s);
	norm.s = s;
	norm.precision = flags->precision;
	ft_int_precision(&witdh, ret_str_l, norm, &i);
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	ft_m_putnbr(i, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void		ft_modulo_plus(va_list *a, int *ret_str_l, t_flags *flags)
{
	char	*s;
	int		i;

	i = va_arg(*a, int);
	if (i != 0 || flags->precision != 0)
	{
		s = ft_itoa2(i);
		if (i >= 0)
			ft_plus_writ(s, flags, ret_str_l, i);
		else
			ft_plus2_writ(s, flags, ret_str_l, i);
	}
}
