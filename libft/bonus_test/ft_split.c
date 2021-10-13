/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:09:49 by dachoi            #+#    #+#             */
/*   Updated: 2021/07/07 20:41:25 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (count);
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_arr(char **arr, int idx)
{
	while (--idx >= 0)
		free(arr[idx]);
	free(arr);
	arr = NULL;
}

static char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (n + 1));
	if (!tmp)
		return (NULL);
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static void	split_str(char **arr, char *s, char c)
{
	size_t	arr_idx;
	size_t	len;

	arr_idx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		arr[arr_idx] = ft_strndup(s - len, len);
		if (!arr[arr_idx])
		{
			free_arr(arr, arr_idx);
			return ;
		}
		arr_idx++;
	}
	arr[arr_idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;

	if (!s)
		return (NULL);
	size = count_str((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	split_str(arr, (char *)s, c);
	return (arr);
}
