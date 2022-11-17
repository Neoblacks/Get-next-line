/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:42 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/17 18:13:36 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[len] = 0;
	return (str);
}

char	*ft_strchr(const char *str, const char *charsearch)
{
	char	*string;

	string = (char *)str;
	while (*string != *charsearch && *string != 0)
		string++;
	if (*string == *charsearch)
		return (string);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t nb)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = '0';
	while (i < nb)
	{
		str[i] = 0;
		i++;
	}
}
