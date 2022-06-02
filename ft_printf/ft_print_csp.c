/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:24:24 by dachoi            #+#    #+#             */
/*   Updated: 2022/01/26 16:29:31 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_print_char(int c, t_opt *opt)
{
	int	len;

	len = 0;
	if (!opt->minus)
	{
		while (--(opt->width) > 0)
			len += write(1, " ", 1);
	}
	len += write(1, &c, 1);
	while (--(opt->width) > 0)
		len += write(1, " ", 1);
	return (len);
}

int	ft_print_str(char *s, t_opt *opt)
{
	int	len;
	int	s_len;

	len = 0;
	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (opt->dot)
		s_len = ft_max(opt->precision, 0);
	if (!opt->minus)
		while ((opt->width)-- > s_len)
			len += write(1, " ", 1);
	while (*s && s_len-- > 0)
	{
		len += write(1, s++, 1);
		opt->width--;
	}
	while ((opt->width)-- > 0)
		len += write(1, " ", 1);
	return (len);
}

int	ft_print_addr(unsigned long addr, t_opt *opt)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(addr, 16) + 2;
	if (!opt->minus)
	{
		while ((opt->width)-- > num_len)
			len += write(1, " ", 1);
	}
	write(1, "0x", 2);
	ft_putnbr_base(addr, "0123456789abcdef", 16);
	len += num_len;
	opt->width -= num_len;
	while ((opt->width)-- > 0)
		len += write(1, " ", 1);
	return (len);
}
