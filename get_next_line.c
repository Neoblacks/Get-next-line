/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:08 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/22 16:21:42 by amugnier         ###   ########.fr       */
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
	return (line);
}

char	*get_next_line(int fd)
{
	static char		rest[BUFFER_SIZE + 1] = {0};
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(rest, '\n') != NULL)
	{
		line = ft_add(line, rest, ft_get_index(rest, '\n') + 1);
		ft_cut(rest, rest);
	}
	else
	{
		if (*rest != '\0')
			line = ft_add(line, rest, BUFFER_SIZE);
		line = readfile(fd, line, rest);
	}
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int	fd;

// 	fd = open(argv[1], O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	free(line);
// }
