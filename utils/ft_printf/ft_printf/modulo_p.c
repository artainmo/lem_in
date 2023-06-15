/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:30:08 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 22:30:01 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_s_init(char *s)
{
	if (!s)
		s = "0";
	else
		s = ft_dec_to_hex_lowercase((unsigned long long int)s);
	return (s);
}

void	ft_modulo_p(char m, va_list *arguments, int *ret_str_l, t_flags *flags)
{
	char	*s;
	int		witdh;
	t_norm	norm;

	s = va_arg(*arguments, char *);
	s = ft_s_init(s);
	witdh = ft_strlen2(s) + 2;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (flags->precision != -1)
	{
		norm.s = s;
		norm.precision = flags->precision;
		ft_u_precision(&witdh, ret_str_l, norm, m);
	}
	if (flags->precision == -1)
	{
		write(1, "0x", 2);
		*ret_str_l = *ret_str_l + 2;
	}
	ft_m_h_putstr(s, ret_str_l);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	s[0] == 0 ? free(s) : s[0];
}
