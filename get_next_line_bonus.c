/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:08 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/23 17:12:16 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_add(char *dest, char *src, ssize_t n)
{
	char	*new;

	if (n != -1)
	{
		new = ft_strnjoin(dest, src, n);
		free(dest);
	}
	return (new);
}

void	ft_cut(char *buffer, char *rest)
{
	ssize_t	len;

	len = ft_get_index(buffer, '\n');
	if (len >= 0)
		ft_strlcpy(rest, buffer + len + 1, BUFFER_SIZE);
}

ssize_t	ft_get_index(char *str, char searched_char)
{
	ssize_t	i;

	i = 0;
	while (str[i] != searched_char && str[i] != '\0')
		i++;
	if (str[i] != searched_char)
		return (-1);
	return (i);
}

char	*readfile(int fd, char *line, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		line = ft_add(line, buffer, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr(buffer, '\n') != NULL)
	{
		line = ft_add(line, buffer, ft_get_index(buffer, '\n') + 1);
		ft_cut(buffer, rest);
	}
	if (bytes == 0 && line == NULL)
		return (NULL);
	if (bytes == 0 && line[0] != '\0')
	{
		ft_bzero(rest, BUFFER_SIZE);
		return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		rest[FOPEN_MAX][BUFFER_SIZE + 1] = {0};
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd > FOPEN_MAX)
		return (NULL);
	if (ft_strchr(rest[fd], '\n') != NULL)
	{
		line = ft_add(line, rest[fd], ft_get_index(rest[fd], '\n') + 1);
		ft_cut(rest[fd], rest[fd]);
	}
	else
	{
		if (*rest[fd] != '\0')
			line = ft_add(line, rest[fd], BUFFER_SIZE);
		line = readfile(fd, line, rest[fd]);
	}
	return (line);
}
