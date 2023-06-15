/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:27:58 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 20:21:40 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_m_putnbr(int nb, int *ret_str_l)
{
	int a;

	a = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*ret_str_l = *ret_str_l + 11;
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		*ret_str_l = *ret_str_l + 1;
	}
	if (nb >= 10)
		ft_m_putnbr(nb / 10, ret_str_l);
	if (!(nb == -2147483648))
	{
		a = nb % 10 + 48;
		write(1, &a, 1);
		*ret_str_l = *ret_str_l + 1;
	}
}
