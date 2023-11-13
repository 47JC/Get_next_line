#include "get_next_line.h"

char *ft_cat(char *dest, char *src)
{
    int len_dest;
    int len_src;
    int i;
    int n;
    char *new;

    n = 0;
    i = 0;
    len_dest = ft_strlen(dest);
    len_src = ft_strlen(src);
    new = malloc(sizeof(char) * (len_dest + len_src + 1));
    if(!new)
        return (NULL);
    while(dest[i])
        new[n++] = dest[i++];
    i = 0;
    while(src[i])
        new[n++] = src[i++];
    new[n] = '\0';
    free(dest);
    return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}