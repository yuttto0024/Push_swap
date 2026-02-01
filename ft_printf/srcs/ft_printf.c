/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:31:13 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:05:21 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_and_print(char c, va_list ap)
{
	static t_convert_formatter	print_table[256];
	static int					is_inittable;

	if (!is_inittable)
	{
		print_table['c'] = ft_putchar;
		print_table['s'] = ft_putstr;
		print_table['p'] = ft_putptr;
		print_table['d'] = ft_putnbr;
		print_table['i'] = ft_putnbr;
		print_table['u'] = ft_putnbr_unsigned;
		print_table['x'] = ft_puthex_low;
		print_table['X'] = ft_puthex_up;
		print_table['%'] = ft_printf_percent;
		is_inittable = 1;
	}
	if (print_table[(unsigned char)c])
		return ((print_table[(unsigned char)c])(ap));
	return (-2);
}

static int	ft_eval_format(const char *fmt, va_list ap, size_t *i)
{
	int	ret;

	if (fmt[*i] == '%')
	{
		if (fmt[*i + 1] == '\0')
			return ((*i)++, -1);
		ret = ft_convert_and_print(fmt[*i + 1], ap);
		if (ret == -1)
			return (-1);
		(*i) += 2;
		if (ret == -2)
		{
			if (write(1, "%", 1) == -1)
				return (-1);
			return ((*i)++, 1);
		}
	}
	else
	{
		ret = write(1, &fmt[*i], 1);
		if (ret == -1)
			return (-1);
		(*i)++;
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total_len;
	int		ret;
	size_t	i;

	i = 0;
	total_len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		ret = ft_eval_format(fmt, ap, &i);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		total_len += ret;
	}
	va_end(ap);
	return (total_len);
}
