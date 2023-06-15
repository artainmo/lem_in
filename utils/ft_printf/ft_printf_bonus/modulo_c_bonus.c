/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:28:07 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 22:13:17 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_c_writ(t_flags *flags, int *ret_str_l, va_list *arguments)
{
	int		witdh;
	wint_t	c;

	c = va_arg(*arguments, wint_t);
	witdh = 1;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	write(1, &c, 1);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	*ret_str_l = *ret_str_l + 1;
}

static void	ft_c2_writ(t_flags *flags, int *ret_str_l, va_list *arguments)
{
	int	witdh;
	int	i;

	i = va_arg(*arguments, int);
	witdh = 1;
	if (!flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	write(1, &i, 1);
	if (flags->minus_flag)
		ft_min_witdh(flags->min_witdh, &witdh, ret_str_l, flags);
	*ret_str_l = *ret_str_l + 1;
}

void		ft_modulo_c(va_list *arguments, int *ret_str_l, t_flags *flags)
{
	if (flags->longs)
		ft_c_writ(flags, ret_str_l, arguments);
	else
		ft_c2_writ(flags, ret_str_l, arguments);
}
