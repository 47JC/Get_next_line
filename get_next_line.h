#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include <strings.h>

char *get_next_line(int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# endif