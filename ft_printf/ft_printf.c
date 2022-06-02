/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:47 by dachoi            #+#    #+#             */
/*   Updated: 2022/01/26 16:05:37 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_opt(t_opt *opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->hash = 0;
	opt->space = 0;
	opt->plus = 0;
	opt->width = 0;
	opt->dot = 0;
	opt->precision = -1;
}

void	ft_parse_flags(char **format, t_opt *opt)
{
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			opt->minus = 1;
		else if (**format == '0')
			opt->zero = 1;
		else if (**format == '#')
			opt->hash = 2;
		else if (**format == ' ')
			opt->space = ' ';
		else if (**format == '+')
			opt->plus = '+';
		(*format)++;
	}
	opt->width = ft_atoi_ptr(format);
	if (**format == '.')
	{
		(*format)++;
		opt->dot = 1;
		if (**format >= '0' && **format <= '9')
			opt->precision = ft_atoi_ptr(format);
	}
}

int	ft_print_type(char *format, t_opt *opt, va_list ap)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len = ft_print_char(va_arg(ap, int), opt);
	else if (*format == 's')
		len = ft_print_str(va_arg(ap, char *), opt);
	else if (*format == 'p')
		len = ft_print_addr((unsigned long)va_arg(ap, void *), opt);
	else if (*format == 'd' || *format == 'i')
		len = ft_print_num(va_arg(ap, int), opt);
	else if (*format == 'u')
		len = ft_print_uint(va_arg(ap, unsigned int), opt);
	else if (*format == 'x')
		len = ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef", opt);
	else if (*format == 'X')
		len = ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF", opt);
	else if (*format == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*form;
	va_list	ap;
	t_opt	options;

	form = (char *)format;
	len = 0;
	va_start(ap, format);
	while (*form != '\0')
	{
		if (*form == '%')
		{
			form++;
			init_opt(&options);
			ft_parse_flags(&form, &options);
			len += ft_print_type(form, &options, ap);
		}
		else
			len += write(1, form, 1);
		form++;
	}
	va_end(ap);
	return (len);
}
