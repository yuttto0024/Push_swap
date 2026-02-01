/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:03:53 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 22:03:53 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	ft_digit_caluc(long ln)
{
	if (ln < 10)
		return (1);
	return (1 + ft_digit_caluc(ln / 10));
}

static char	*ft_fill_string(char *p, long ln, size_t len, int is_negative)
{
	len--;
	while (ln > 0)
	{
		p[len] = (ln % 10) + '0';
		ln = ln / 10;
		len--;
	}
	if (is_negative)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	ln;
	char	*p;
	int		is_negative;

	if (n == 0)
		return (ft_strdup("0"));
	ln = (long)n;
	is_negative = 0;
	if (ln < 0)
	{
		ln = ln * (-1);
		is_negative = 1;
	}
	len = ft_digit_caluc(ln);
	if (is_negative)
		len++;
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	return (ft_fill_string(p, ln, len, is_negative));
}

/*
int	main(void)
{
	char	*p;

	p = ft_itoa(-2147483648);
	printf("%s\n", p);
}
*/
