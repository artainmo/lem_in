/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_H.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:27:04 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:12:26 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_h_writ(char m, t_flags *flags, int *ret_str_l, unsigned long int ul)
{
	int		witdh;
	char	*s;
	t_norm	norm;

	s = ft_decimal_to_hexadecimal_uppercase(ul);
	witdh = ft_strlen2(s) + 2;
	if (flags->precision != -1)
	{
		norm.s = s;
		norm.precision = flags->precision;
		ft_u_precision(&witdh, ret_str_l, norm, m);
	}
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	norm.s = s;
	norm.precision = flags->precision;
	ft_u_precision(&witdh, ret_str_l, norm, m);
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void	ft_h2_writ(char m, t_flags *flags, int *ret_str_l, unsigned long int ul)
{
	int		witdh;
	char	*s;
	t_norm	norm;

	s = ft_decimal_to_hexadecimal_uppercase(ul);
	witdh = 1;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (flags->precision != -1)
	{
		norm.s = s;
		norm.precision = flags->precision;
		ft_u_precision(&witdh, ret_str_l, norm, m);
	}
	write(1, "0", 1);
	*ret_str_l = *ret_str_l + 1;
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void	ft_modulo_h(char m, va_list *arguments, int *ret_str_l, t_flags *flags)
{
	unsigned long int	ul;

	ul = va_arg(*arguments, unsigned long int);
	if (ul != 0 || flags->precision != 0)
	{
		if (ul != 0)
			ft_h_writ(m, flags, ret_str_l, ul);
		else
			ft_h2_writ(m, flags, ret_str_l, ul);
	}
}
