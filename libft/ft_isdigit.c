/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:38:31 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 18:35:51 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = '0';
	j = '9';
	k = '/';
	printf("---isdigit---\n");
	l = isdigit(i);
	printf("i:%d\n", l);
	l = isdigit(j);
	printf("j:%d\n", l);
	l = isdigit(k);
	printf("k:%d\n", l);

	printf("---ft_isdigit---\n");
	l = ft_isdigit(i);
	printf("i:%d\n", l);
	l = ft_isdigit(j);
	printf("j:%d\n", l);
	l = ft_isdigit(k);
	printf("k:%d\n", l);
}
*/
