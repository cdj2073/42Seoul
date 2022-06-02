/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:18:09 by dachoi            #+#    #+#             */
/*   Updated: 2022/01/26 17:53:47 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_flags(t_opt *opt, unsigned long num, char *base)
{
	int	len;

	len = 0;
	if (!opt->minus && opt->width > 0)
	{
		while ((opt->width)-- > 0)
			len += write(1, " ", 1);
	}
	if (opt->hash && num != 0 && base[10] == 'a')
		len += write(1, "0x", 2);
	else if (opt->hash && num != 0 && base[10] == 'A')
		len += write(1, "0X", 2);
	if (opt->plus)
		len += write(1, (void *)&opt->plus, 1);
	else if (opt->space)
		len += write(1, (void *)&opt->space, 1);
	return (len);
}

int	ft_putall(t_opt *opt, unsigned long num, char *base)
{
	int	len;

	len = 0;
	if (num == 0 && opt->dot)
	{
		opt->width += ft_max(opt->hash, 0) + ft_nbrlen(num, ft_strlen(base));
		if (opt->plus || opt->space)
			opt->width += 2;
		while ((opt->precision)-- > 0)
			len += write(1, "0", 1);
	}
	else
	{
		len += ft_put_flags(opt, num, base);
		while ((opt->precision)-- > 0 || (opt->zero)-- > 0)
			len += write(1, "0", 1);
		ft_putnbr_base(num, base, ft_strlen(base));
		len += ft_nbrlen(num, ft_strlen(base));
	}
	while ((opt->width)-- > 0)
		len += write(1, " ", 1);
	return (len);
}

int	ft_print_num(int nbr, t_opt *opt)
{
	int				len;
	int				num_len;
	unsigned long	num;

	len = 0;
	num = (unsigned long)nbr;
	if (nbr < 0)
	{
		num *= -1;
		opt->plus = '-';
	}
	num_len = ft_nbrlen(num, 10);
	if (opt->plus || opt->space)
		opt->width--;
	if (opt->zero)
		opt->zero = ft_max(opt->width - num_len, 0);
	if (opt->dot)
	{
		opt->zero = 0;
		if (opt->precision >= 0 && nbr != 0)
			opt->precision = ft_max(opt->precision - num_len, 0);
	}
	opt->width = opt->width - opt->zero - ft_max(opt->precision, 0) - num_len;
	len += ft_putall(opt, num, "0123456789");
	return (len);
}

int	ft_print_uint(unsigned int num, t_opt *opt)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(num, 10);
	if (opt->plus || opt->space)
		opt->width--;
	if (opt->zero)
		opt->zero = ft_max(opt->width - num_len, 0);
	if (opt->dot)
	{
		opt->zero = 0;
		if (opt->precision >= 0 && num != 0)
			opt->precision -= num_len;
	}
	opt->width = opt->width - opt->zero - ft_max(opt->precision, 0) - num_len;
	len += ft_putall(opt, num, "0123456789");
	return (len);
}

int	ft_print_hex(unsigned int num, char *base, t_opt *opt)
{
	int		len;
	int		num_len;

	len = 0;
	num_len = ft_nbrlen(num, 16);
	if (opt->zero)
		opt->zero = ft_max(opt->width - num_len, 0);
	if (opt->hash)
		opt->zero = ft_max(opt->zero - 2, 0);
	if (opt->dot)
	{
		opt->zero = 0;
		if (opt->precision >= 0 && num != 0)
			opt->precision = ft_max(opt->precision - num_len, 0);
	}
	opt->width = opt->width - opt->hash - opt->zero - num_len;
	opt->width -= ft_max(opt->precision, 0);
	opt->space = 0;
	opt->plus = 0;
	len += ft_putall(opt, num, base);
	return (len);
}
