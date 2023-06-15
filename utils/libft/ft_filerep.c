/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:52:28 by artainmo          #+#    #+#             */
/*   Updated: 2019/10/17 23:21:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_file_rep(char *filename, char trim, char replace)
{
	int		ret;
	int		fd;
	char	buffer[2];
	char	*new_file;

	new_file = NULL;
	if ((fd = open(filename, O_RDWR, 0666)) == -1)
		return (0);
	while ((ret = read(fd, buffer, 1)))
	{
		buffer[1] = '\0';
		if (buffer[0] == trim)
			buffer[0] = replace;
		if (!(new_file = ft_strjoin_f(new_file, buffer, 1)))
			return (0);
		if (ret == -1)
			return (0);
	}
	fd = open(filename, O_RDWR | O_TRUNC, 0666);
	write(fd, new_file, ft_strlen(new_file));
	close(fd);
	return (1);
}
