/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:01:54 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:17:45 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_recursive(unsigned long n, const char *base)
{
	int	len;
	int	ret;

	len = 0;
	ret = 0;
	if (n >= 16)
	{
		ret = ft_puthex_recursive(n / 16, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_puthex_low(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789abcdef"));
}

int	ft_puthex_up(va_list ap)
{
	return (ft_puthex_recursive(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
