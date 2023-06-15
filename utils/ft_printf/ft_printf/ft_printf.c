/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:24:45 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/24 01:04:01 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_error;

int	ft_modul(int modulo_type, va_list *arguments, int *ret_str_l, t_flags flag)
{
	if (modulo_type == 'E')
		return (-1);
	if (flag.blank_space == 1)
	{
		write(1, " ", 1);
		*ret_str_l = *ret_str_l + 1;
	}
	ft_write_argument(modulo_type, arguments, ret_str_l, &flag);
	return (0);
}

int	f_p(va_list *arguments, const char *format, t_flags flag, char modulo_type)
{
	int i;
	int writ;
	int ret_str_l;

	i = 0;
	ret_str_l = 0;
	while (format[i])
	{
		writ = 1;
		if ((modulo_type = ft_find_modulo((format + i), &i, &flag, arguments)))
			writ = ft_modul(modulo_type, arguments, &ret_str_l, flag);
		if (writ)
		{
			write(1, &format[i], 1);
			ret_str_l++;
		}
		i++;
	}
	va_end(*arguments);
	if (g_error)
		return (-1);
	return (ret_str_l);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	t_flags	flag;
	char	modulo_type;

	flag.blank_space = 0;
	flag.min_witdh = 0;
	flag.minus_flag = 0;
	flag.flag_0 = 0;
	flag.precision = -1;
	flag.longs = 0;
	flag.long_long = 0;
	flag.chars = 0;
	flag.shorts = 0;
	flag.flag_point = 0;
	flag.neg = 0;
	modulo_type = 0;
	va_start(arguments, format);
	return (f_p(&arguments, format, flag, modulo_type));
}
