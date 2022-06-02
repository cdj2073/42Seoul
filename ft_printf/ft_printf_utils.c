/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:38:51 by dachoi            #+#    #+#             */
/*   Updated: 2022/01/26 16:16:27 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int	ft_atoi_ptr(char **s)
{
	int	num;

	num = 0;
	while (**s && **s >= '0' && **s <= '9')
	{
		num = 10 * num + (**s - '0');
		(*s)++;
	}
	return (num);
}

void	ft_putnbr_base(unsigned long num, char *base, int base_len)
{
	if (num < (unsigned long)base_len)
		write(1, &base[num % base_len], 1);
	else
	{
		ft_putnbr_base(num / base_len, base, base_len);
		write(1, &base[num % base_len], 1);
	}
}

int	ft_nbrlen(unsigned long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
