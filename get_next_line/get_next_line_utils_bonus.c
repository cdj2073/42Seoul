#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s || len == 0)
		return (NULL);
	i = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
    if (s1)
        free((void *)s1);
    return (str);
}
