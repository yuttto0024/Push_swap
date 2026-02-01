/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:21:34 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:50 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	char	test1[] = "Happy";
	size_t	l;

	printf("---strlen---\n");
	l = strlen(test1);
	printf("%s:%zu\n", test1, l);
	printf("---ft_strlen---\n");
	l = ft_strlen(test1);
	printf("%s:%zu\n", test1, l);
}
*/