/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:56:18 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:08:21 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = '0';
	j = 'a';
	k = '/';
	printf("---isalnum---\n");
	l = isalnum(i);
	printf("i:%d\n", l);
	l = isalnum(j);
	printf("j:%d\n", l);
	l = isalnum(k);
	printf("k:%d\n", l);

	printf("---ft_isalnum---\n");
	l = ft_isalnum(i);
	printf("i:%d\n", l);
	l = ft_isalnum(j);
	printf("j:%d\n", l);
	l = ft_isalnum(k);
	printf("k:%d\n", l);
}
*/
