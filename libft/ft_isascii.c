/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:06:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 18:35:20 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isascii(int c)
{
	return (c >= '\0' && c <= 127);
}

/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = '\0';
	j = '<';
	k = -42;
	printf("---isascii---\n");
	l = isascii(i);
	printf("i:%d\n", l);
	l = isascii(j);
	printf("j:%d\n", l);
	l = isascii(k);
	printf("k:%d\n", l);

	printf("---ft_isascii---\n");
	l = ft_isascii(i);
	printf("i:%d\n", l);
	l = ft_isascii(j);
	printf("j:%d\n", l);
	l = ft_isascii(k);
	printf("k:%d\n", l);
}
*/
