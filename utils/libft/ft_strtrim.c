/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:08:26 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/22 16:28:05 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Trims until it finds a char that doesn’t need to
**	be trimmed starting from begin string and does the
**	same starting from end string.
*/

static char	*ft_emptystr(void)
{
	char *str;

	if (!(str = malloc(sizeof(char))))
		return (0);
	str[0] = '\0';
	return (str);
}

static int	ft_is_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim_begin(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (ft_is_set(s1[i], set))
		i++;
	return (i);
}

static int	ft_trim_end(char const *s1, char const *set)
{
	int	i;
	int	counter;

	i = ft_strlen(s1) - 1;
	counter = 0;
	while (ft_is_set(s1[i], set))
	{
		i--;
		counter++;
	}
	return (counter);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		start;
	int		lenght;

	if (s1 == NULL || set == NULL)
		return (ft_emptystr());
	start = ft_trim_begin(s1, set);
	if (start == ft_strlen(s1))
		return (ft_emptystr());
	lenght = ft_strlen(s1) - ft_trim_end(s1, set) - start;
	if (!(cpy = ft_substr(s1, start, lenght)))
		return (0);
	return (cpy);
}
