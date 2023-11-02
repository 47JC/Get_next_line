#include "get_next_line.h"

char *get_next_line(int fd)
{
    char new[1];
    char *temp;
    int n = 0;
    char *retorno;
    int i;
    
    new[0] = 0;
    temp = malloc(sizeof(char) * 100);
    while (new[0] != '\n')    
    {
        i = read(fd, new, 1);
        if (i == 0)
        {
            temp[n] = 0;
            retorno = strdup(temp);
            return (retorno);
        }
        temp[n++] = new[0];
        if (n >= BUFFER_SIZE)
            n = 0;        
    }
    temp[n] ='\0';
    retorno = strdup(temp);
    free(temp);
    return (retorno);
}

int main()
{
    int fd;
    static char *line;

    fd = open("test.txt", O_RDONLY);
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    printf("|%s|", get_next_line(fd));
    return (0);
}