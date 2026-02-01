/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:03:12 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/25 22:11:03 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(va_list ap)
{
	char	*str;
	size_t	i;

	str = va_arg(ap, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	if (i > 2147483647)
		return (-1);
	return ((int)i);
}

int	ft_printf_percent(va_list ap)
{
	(void)ap;
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
