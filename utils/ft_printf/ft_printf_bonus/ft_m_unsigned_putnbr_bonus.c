/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_unsigned_putnbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:22:10 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/23 20:22:15 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_m_unsigned_putnbr(unsigned int nb, int *ret_str_l)
{
	unsigned int a;

	a = 0;
	if (nb >= 10)
		ft_m_unsigned_putnbr(nb / 10, ret_str_l);
	a = nb % 10 + 48;
	write(1, &a, 1);
	*ret_str_l = *ret_str_l + 1;
}
