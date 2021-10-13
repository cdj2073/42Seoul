/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:44:48 by dachoi            #+#    #+#             */
/*   Updated: 2021/07/05 20:56:00 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!sub[i])
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (str[i + j] && sub[j] && str[i + j] == sub[j] && i + j < len)
			j++;
		if (sub[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
