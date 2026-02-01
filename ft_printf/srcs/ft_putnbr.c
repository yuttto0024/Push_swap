/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:39:11 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:10:57 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(long n)
{
	int		len;
	int		ret;
	char	c;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_putnbr_recursive(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putnbr(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	return (ft_putnbr_recursive((long)n));
}
