/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:18:47 by dachoi            #+#    #+#             */
/*   Updated: 2022/01/26 16:33:45 by dachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_opt
{
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	dot;
	int	precision;
}	t_opt;

int		ft_printf(const char *format, ...);

void	init_opt(t_opt *opt);
void	ft_parse_flags(char **format, t_opt *opt);

int		ft_print_char(int c, t_opt *opt);
int		ft_print_str(char *s, t_opt *opt);
int		ft_print_addr(unsigned long addr, t_opt *opt);
int		ft_print_num(int nbr, t_opt *opt);
int		ft_print_uint(unsigned int num, t_opt *opt);
int		ft_print_hex(unsigned int num, char *base, t_opt *opt);

int		ft_max(int a, int b);
int		ft_strlen(char *s);
int		ft_nbrlen(unsigned long num, int base);
int		ft_atoi_ptr(char **s);
char	*ft_strchr(char *s, int c);
void	ft_putnbr_base(unsigned long num, char *base, int len);

#endif
