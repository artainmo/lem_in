/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:05:27 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/22 19:35:18 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!(lst == NULL || del == NULL))
	{
		while (*lst)
		{
			l = *lst;
			del((*lst)->content);
			free(*lst);
			*lst = (l)->next;
		}
	}
}
