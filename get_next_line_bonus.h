#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	1000

# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_line(char *left_str);
char	*ft_next(char *left_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif