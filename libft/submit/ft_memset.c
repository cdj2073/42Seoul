/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:39:35 by dachoi            #+#    #+#             */
/*   Updated: 2021/07/07 13:22:12 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*ptr;

	i = 0;
	value = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = value;
	return (b);
}
