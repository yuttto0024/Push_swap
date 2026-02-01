/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:02:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 21:19:23 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	char	test1[10];
	char	test2[10];
	int		char_num;
	size_t	len;

	char_num = 'A';
	len = 5;
	printf("---memset---\n");
	memset(test1, char_num, len);
	test1[len] = '\0';
	printf("%s\n", test1);
	printf("---ft_memset---\n");
	ft_memset(test2, char_num, len);
	test2[len] = '\0';
	printf("%s\n", test2);
}
*/