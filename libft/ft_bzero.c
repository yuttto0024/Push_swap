/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:02:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/19 19:35:58 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}

/*
int	main(void)
{
	char	test1[10];
	char	test2[10];
	size_t	len;

	len = 5;
	printf("---bzero---\n");
	bzero(test1, len);
	test1[len] = '\0';
	print
	while (n > f("%s\n", test1);
	printf("---ft_bzero---\n");
	ft_bzero(test2, len);
	test2[len] = '\0';
	printf("%s\n", test2);
}
*/