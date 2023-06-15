/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_modulo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:19:46 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/30 20:27:25 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_find_specifier2(char c, char cminone)
{
	if (c == 'x' && cminone == '#')
		return ('#');
	else if (c == 'x')
		return ('x');
	else if (c == 'X' && cminone == '#')
		return ('H');
	else if (c == 'X')
		return ('X');
	else if (c == '%')
		return ('%');
	else if (c == 'n')
		return ('n');
	else if (c == 'f')
		return ('f');
	else if (c == 'e')
		return ('e');
	else if (c == 'g')
		return ('g');
	return (0);
}

void	flag_comb(t_flags *flag, char m_t)
{
	if (flag->min_witdh < 0)
	{
		flag->minus_flag = 1;
		flag->min_witdh = flag->min_witdh * -1;
	}
	if (flag->precision < 0)
		flag->precision = -1;
	if (flag->minus_flag && flag->flag_0 && m_t)
		flag->flag_0 = 0;
	if (flag->flag_0 && flag->precision != -1 && m_t != 'f' && m_t != 'e'
			&& m_t != 'g')
		flag->flag_0 = 0;
}

void	ft_flag_init(t_flags *flag)
{
	flag->blank_space = 0;
	flag->min_witdh = 0;
	flag->minus_flag = 0;
	flag->flag_0 = 0;
	flag->precision = -1;
	flag->longs = 0;
	flag->long_long = 0;
	flag->chars = 0;
	flag->shorts = 0;
	flag->flag_point = 0;
}
