/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:09:45 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/22 16:30:22 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list *res;

	if (!(res = malloc(sizeof(t_list) * ft_lstsize(lst))))
		return (0);
	if (!res)
	{
		del(res);
		free(res);
	}
	res = lst;
	while (res)
	{
		res->content = f(res->content);
		res = res->next;
	}
	return (lst);
}
