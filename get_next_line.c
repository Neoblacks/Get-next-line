/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:08 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/19 20:38:09 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add(char *dest, char *src, ssize_t n)
{
	char	*new;

	new = ft_strnjoin(dest, src, n);
	free(dest);
	return (new);
}

void	ft_cut(char *buffer, char **line, char *rest)
{
	ssize_t	len;

	len = ft_get_index(buffer, '\n');
	if(!*line)
		return ;
	*line = ft_add(*line, buffer, len);
	ft_strlcpy(rest, buffer + len, BUFFER_SIZE - len + 1);
}

char	*readFile(int fd, char *line, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 && ft_strchr(buffer, "\n") != NULL)
	{
		line = ft_add(line, buffer, ft_get_index(buffer, '\n'));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	ft_cut(buffer, &line, rest);
}

char	*get_next_line(int fd)
{
	static char		rest[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readFile(fd, line, rest);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("[%s]", line);
	}
	close(fd);
	free(line);
}
