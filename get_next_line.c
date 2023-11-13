#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *ft_cat(char *dest)
{
    char *new;
    int len;
    int i;

    if(!dest)
    {
        dest = malloc(sizeof(char) * 1);
        if(!dest)
            return (NULL);
    }
    i = -1;
    len = ft_strlen(dest);
    new = malloc(sizeof(char) * len + BUFFER_SIZE + 1);
    if(!new)
        return (NULL);
    while(dest[++i])
        new[i] = dest[i];
    while (i < len + BUFFER_SIZE + 1)
        new[i++] = 0;
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

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *newline;
    int n = 0;
    int i;
    int y;
    //Seguranca
    if (read(fd, buffer, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    i = read(fd, buffer, BUFFER_SIZE);
    newline = malloc(1 * sizeof(char));
    if (!newline)
        return (NULL);
    newline[0] = 0;
    while(buffer[n] != '\n' && i == BUFFER_SIZE)
    {
        newline = ft_cat(newline);
        y = ft_strlen(newline);
        while (buffer[n] && buffer[n] != '\n')
            newline[y++] = buffer[n++];
        if (buffer[n] == '\n')
        {
            return (newline);
        }
        newline[y] = 0;
        i = read(fd, buffer, BUFFER_SIZE);
        n = 0;
    }
    return (newline);
}

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    return (0);
}