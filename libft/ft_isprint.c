/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:20:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 18:32:03 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = '\0';
	j = '\200';
	k = EOF;
	printf("---isprint---\n");
	l = isprint(i);
	printf("i:%d\n", l);
	l = isprint(j);
	printf("j:%d\n", l);
	l = isprint(k);
	printf("k:%d\n", l);

	printf("---ft_isprint---\n");
	l = ft_isprint(i);
	printf("i:%d\n", l);
	l = ft_isprint(j);
	printf("j:%d\n", l);
	l = ft_isprint(k);
	printf("k:%d\n", l);
}
*/
