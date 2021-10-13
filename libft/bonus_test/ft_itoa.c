/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:23:33 by dachoi            #+#    #+#             */
/*   Updated: 2021/07/07 14:14:20 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	get_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = get_len(n);
	i = len - 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = get_abs(n % 10) + '0';
		n /= 10;
		if (!n)
			break ;
	}
	if (i == 0)
		str[i] = '-';
	str[len] = '\0';
	return (str);
}
