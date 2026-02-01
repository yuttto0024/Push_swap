/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:38:02 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 20:19:05 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		target;
	size_t				i;

	src = (const unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == target)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	s[] = "Happy";
	int		c;
	size_t	n;

	c = 'p';
	n = 5;
	printf("---memchr---\n");
	printf("%p\n", memchr(s, c, n));
	printf("---ft_memchr---\n");
	printf("%p\n", ft_memchr(s, c, n));
}
*/
