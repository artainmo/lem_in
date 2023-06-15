/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:25:20 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 21:45:44 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** This function recognizes the modulo specifier,
** stores the variadic arguments in a variable
** and writes the argument arcordingly, and keeps counting
** the written flags->chars
*/

void	ft_modulo_mod(int *ret_str_l, t_flags *flags)
{
	int witdh;

	witdh = 1;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	write(1, "%", 1);
	*ret_str_l = *ret_str_l + 1;
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
}

void	ft_writ(char m, va_list *a, int *ret_str_l, t_flags *flags)
{
	if (m == 'H')
		ft_modulo_h(m, a, ret_str_l, flags);
	if (m == 'X')
		ft_modulo_bx(m, a, ret_str_l, flags);
	if (m == '%')
		ft_modulo_mod(ret_str_l, flags);
	if (m == 'n')
		ft_modulo_n(a, ret_str_l, flags);
	if (m == 'f')
		ft_modulo_f(a, ret_str_l, flags);
	if (m == 'e')
		ft_modulo_e(a, ret_str_l, flags);
	if (m == 'g')
		ft_modulo_g(a, ret_str_l, flags);
}

void	ft_write_argument(char m, va_list *a, int *ret_str_l, t_flags *flags)
{
	if (m == 'c')
		ft_modulo_c(a, ret_str_l, flags);
	if (m == 's')
		ft_modulo_s(a, ret_str_l, flags);
	if (m == 'p')
		ft_modulo_p(m, a, ret_str_l, flags);
	if (m == '+' || m == 'P')
		ft_modulo_plus(a, ret_str_l, flags);
	if (m == 'd' || m == 'i')
		ft_modulo_i(a, ret_str_l, flags);
	if (m == 'u')
		ft_modulo_u(m, a, ret_str_l, flags);
	if (m == '#')
		ft_modulo_hash(m, a, ret_str_l, flags);
	if (m == 'x')
		ft_modulo_x(m, a, ret_str_l, flags);
	ft_writ(m, a, ret_str_l, flags);
}
