/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:23:24 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:05 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t				i;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	s1[] = "Hello World";
	char	s2[] = "Hello Planet";
	size_t	i;

	i = 10;
	printf("---memcmp---\n");
	printf("%d\n", memcmp(s1, s2, i));
	printf("---ft_memcmp---\n");
	printf("%d\n", memcmp(s1, s2, i));
}
*/