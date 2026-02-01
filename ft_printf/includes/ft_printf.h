/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:41:26 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:18:11 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef int	(*t_convert_formatter)(va_list);
int			ft_printf(const char *fmt, ...);
int			ft_putchar(va_list ap);
int			ft_putstr(va_list ap);
int			ft_printf_percent(va_list ap);
int			ft_putnbr(va_list ap);
int			ft_putnbr_unsigned(va_list ap);
int			ft_puthex_low(va_list ap);
int			ft_puthex_up(va_list ap);
int			ft_putptr(va_list ap);

#endif