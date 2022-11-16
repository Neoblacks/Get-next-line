#include "get_next_line.h"


char    *ft_free(char *buffer, char *buff)
{
    char    *tmp;

    tmp = ft_strjoin(buffer, buff);
    free(buffer);
    return (tmp);
}

char    *ft_next(char *buffer)
{
    int    i;
    int    j;
    char    *str;

    i = 0;
    while(buffer[i] != '\n' && buffer[i] != 0)
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    str = malloc(sizeof(char) * ft_strlen(buffer - i + 1 ));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (buffer[i] != '\0')
        str[j++] = buffer[i++];\
    free(buffer);
    return (str);
}