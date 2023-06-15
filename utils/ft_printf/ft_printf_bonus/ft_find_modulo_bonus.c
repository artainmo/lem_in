/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:19:33 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/29 18:25:54 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** This function finds the modulo specifier and number of spaces
**between modulo and specifier
** it returns the specifier type and increments i accordingly with pointer m
** it returns how many blank spaces were found if one the function that calls
** this one will write one space
*/

char	ft_find_specifier(char c, char cminone)
{
	if (c == 'c')
		return ('c');
	else if (c == 's')
		return ('s');
	else if (c == 'p')
		return ('p');
	else if (c == 'd' && cminone == '+')
		return ('+');
	else if (c == 'd')
		return ('d');
	else if (c == 'i' && cminone == '+')
		return ('P');
	else if (c == 'i')
		return ('i');
	else if (c == 'u')
		return ('u');
	else
		return (ft_find_specifier2(c, cminone));
}

void	ft_find_flags(char c, char cminone, t_flags *flags, va_list *arguments)
{
	if (c == ' ')
		flags->blank_space = flags->blank_space + 1;
	else if (c == '.')
	{
		flags->flag_point = 1;
		flags->precision = 0;
	}
	else if (c == '-')
		flags->minus_flag = 1;
	else if (c == '0' && !flags->flag_0 && !flags->flag_point)
		flags->flag_0 = 1;
	else if (c == '*' && flags->flag_point)
		flags->precision = va_arg(*arguments, int);
	else if (c == '*')
		flags->min_witdh = va_arg(*arguments, int);
	else if (c == 'l' && cminone == 'l')
		flags->long_long = 1;
	else if (c == 'l')
		flags->longs = 1;
	else if (c == 'h' && cminone == 'h')
		flags->chars = 1;
	else if (c == 'h')
		flags->shorts = 1;
}

void	ft_count_precision(t_flags *flags, int *i, const char *s, int *r)
{
	char	*tmp_witdh;
	int		mall;

	mall = *i;
	*r = 0;
	while (s[mall] > 47 && s[mall] < 58)
		mall++;
	mall++;
	mall = mall - *i;
	if (!(tmp_witdh = malloc(sizeof(char) * mall)))
		g_error = 1;
	if (s[*i] > 47 && s[*i] < 58)
	{
		while (s[*i] > 47 && s[*i] < 58)
		{
			tmp_witdh[*r] = s[*i];
			*i = *i + 1;
			*r = *r + 1;
		}
		tmp_witdh[*r] = '\0';
		flags->precision = ft_atoi(tmp_witdh);
		*i = *i - 1;
		*r = *r - 1;
		free(tmp_witdh);
	}
}

void	ft_count_min_witdh(t_flags *flags, int *i, const char *s, int *r)
{
	char	*tmp_witdh;
	int		mall;

	*r = 0;
	if (s[*i] > 47 && s[*i] < 58)
	{
		mall = *i;
		while (s[mall] > 47 && s[mall] < 58)
			mall++;
		mall++;
		mall = mall - *i;
		if (!(tmp_witdh = malloc(sizeof(char) * mall)))
			g_error = 1;
		while (s[*i] > 47 && s[*i] < 58)
		{
			tmp_witdh[*r] = s[*i];
			*i = *i + 1;
			*r = *r + 1;
		}
		tmp_witdh[*r] = '\0';
		flags->min_witdh = ft_atoi(tmp_witdh);
		*i = *i - 1;
		*r = *r - 1;
		free(tmp_witdh);
	}
}

char	ft_find_modulo(const char *format, int *m, t_flags *flags, va_list *a)
{
	int i;
	int r;

	i = 0;
	r = 0;
	ft_flag_init(flags);
	if (format[i] == '%')
	{
		while (format[i])
		{
			i++;
			*m = *m + 1 + r;
			if (ft_find_specifier(format[i], format[i - 1]))
			{
				flag_comb(flags, ft_find_specifier(format[i], format[i - 1]));
				return (ft_find_specifier(format[i], format[i - 1]));
			}
			ft_find_flags(format[i], format[i - 1], flags, a);
			flags->flag_point ? ft_count_precision(flags, &i, format, &r) :
						ft_count_min_witdh(flags, &i, format, &r);
		}
		*m = *m + 1 - i;
		return (0);
	}
	return (0);
}
