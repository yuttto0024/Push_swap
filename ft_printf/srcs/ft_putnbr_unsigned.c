/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:56:16 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:14:28 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned_recursive(unsigned int n)
{
	int		len;
	int		ret;
	char	c;

	len = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_unsigned_recursive(n / 10);
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

int	ft_putnbr_unsigned(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_unsigned_recursive(n));
}
