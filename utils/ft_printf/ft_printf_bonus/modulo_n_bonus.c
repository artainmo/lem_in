/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:29:52 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 22:42:58 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_n_writ(int *ret_str_l, va_list *arguments)
{
	va_arg(*arguments, int);
	*ret_str_l = *ret_str_l; //Avoid compilation error
}

void	ft_n2_writ(int *ret_str_l, va_list *arguments)
{
	va_arg(*arguments, int);
	*ret_str_l = *ret_str_l; //Avoid compilation error
}

void	ft_n3_writ(int *ret_str_l, va_list *arguments)
{
	va_arg(*arguments, long long int);
	*ret_str_l = *ret_str_l; //Avoid compilation error
}

void	ft_n4_writ(int *ret_str_l, va_list *arguments)
{
	va_arg(*arguments, long int);
	*ret_str_l = *ret_str_l; //Avoid compilation error
}

void	ft_modulo_n(va_list *arguments, int *ret_str_l, t_flags *flags)
{
	if (flags->chars)
		ft_n_writ(ret_str_l, arguments);
	else if (flags->shorts)
		ft_n2_writ(ret_str_l, arguments);
	else if (flags->long_long)
		ft_n3_writ(ret_str_l, arguments);
	else if (flags->longs)
		ft_n4_writ(ret_str_l, arguments);
	else
	{
		va_arg(*arguments, int);
		*ret_str_l = *ret_str_l; //Avoid compilation error
	}
}
