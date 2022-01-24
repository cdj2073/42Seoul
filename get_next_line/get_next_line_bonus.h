#ifndef FT_GET_NEXT_LINE_BONUS_H
# define FT_GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list {
    int fd;
    char    *data;
    struct s_list   *next;
} t_list;

char    *get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t num);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
