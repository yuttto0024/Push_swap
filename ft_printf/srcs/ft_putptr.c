/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:09:30 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:11:09 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_recursive(unsigned long n, char *base)
{
	int	len;
	int	ret;

	len = 0;
	ret = 0;
	if (n >= 16)
	{
		ret = ft_putptr_recursive(n / 16, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putptr(va_list ap)
{
	unsigned long	ptr;
	int				len;
	int				ret;

	ptr = (unsigned long)va_arg(ap, void *);
	len = 0;
	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	ret = ft_putptr_recursive(ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
