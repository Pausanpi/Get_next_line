#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	1000

# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_line(char *left_str);
char	*ft_next(char *left_str);

#endif