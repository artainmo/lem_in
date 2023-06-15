/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:37:42 by artainmo          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *text)
{
	write(2, text, ft_strlen(text));
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putstr_fd("Malloc failed\n", 2);
	exit(1);
}

void	ft_errno(void)
{
	char *error_message;

	error_message = strerror(errno);
	ft_putendl_fd(error_message, 2);
	exit(1);

}
