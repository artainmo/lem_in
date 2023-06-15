/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_#.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:26:26 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/25 18:12:47 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_hash_w(int m, t_flags *f, int *ret_str_l, unsigned long int ul)
{
	int		witdh;
	char	*s;
	t_norm	norm;

	s = ft_dec_to_hex_lowercase(ul);
	witdh = ft_strlen2(s) + 2;
	norm.s = s;
	norm.precision = f->precision;
	ft_u_precision(&witdh, ret_str_l, norm, m);
	if (!f->minus_flag)
		ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f);
	ft_m_h_putstr(s, ret_str_l);
	if (f->minus_flag)
		ft_min_witdh(f->min_witdh, &witdh, ret_str_l, f);
	free(s);
}

static void	ft_hash_writ2(int modulo_type, t_flags *flags, int *ret_str_l)
{
	int		witdh;
	char	*s;
	t_norm	norm;

	witdh = 1;
	s = NULL;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	if (flags->precision != -1)
	{
		norm.s = s;
		norm.precision = flags->precision;
		ft_u_precision(&witdh, ret_str_l, norm, modulo_type);
	}
	write(1, "0", 1);
	*ret_str_l = *ret_str_l + 1;
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	free(s);
}

void		ft_modulo_hash(char m, va_list *a, int *ret_str_l, t_flags *flags)
{
	unsigned long int	ul;

	ul = va_arg(*a, unsigned long);
	if (ul != 0 || flags->precision != 0)
	{
		if (ul != 0)
			ft_hash_w(m, flags, ret_str_l, ul);
		else
			ft_hash_writ2(m, flags, ret_str_l);
	}
}
