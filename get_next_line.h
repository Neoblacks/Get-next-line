/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:46:42 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/19 20:02:17 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char		*get_next_line(int fd);
char		*ft_strnjoin(char const *s1, char const *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *str, const char *charsearch);
void		ft_bzero(void *s, size_t nb);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
ssize_t		ft_get_index(char *str, char searched_char);
void		*ft_calloc(size_t count, size_t size);

#endif
