/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:08 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/17 21:43:47 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add(char *buffer, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	return (tmp);
}

void	ft_cut(char *buffer, char **line, char *rest)
{
}

char	*readFile(int fd, char *line, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 && ft_strchr(buffer, '\n') != NULL)
	{
		line = ft_add(line, buffer);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	ft_cut(buffer, line, rest);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	// buffer = ft_strchr('\n');
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * ft_strlen(buffer - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (fd < 0 || read(fd, 0, 0) <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer =; //fonction qui renvoie la ligne ?
	if (!buffer)
		return (NULL);
	line =; //ft pour get la ligne;
	buffer =; //ft_next;

	return (line);
}
//read file function

//get next line function final

// int	main(void)
// {
// 	int	fd;

// 	fd = open(argv[1(chemin du fichier)], FLAGS);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		printf("[%s]", line);
// 	}
// 	close(fd);
// 	free(line);
// }
