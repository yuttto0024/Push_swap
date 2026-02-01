/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:30:28 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/26 14:51:04 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
/*
int	main(void)
{
	int	i;
	int	j;
	int	l;

	i = 'A';
	j = '0';
	printf("---tolower---\n");
	l = tolower(i);
	printf("%d ~> %d\n", i, l);
	l = tolower(j);
	printf("%d ~> %d\n", j, l);

	printf("---ft_tolower---\n");
	l = ft_tolower(i);
	printf("%d ~> %d\n", i, l);
	l = ft_tolower(j);
	printf("%d ~> %d\n", j, l);
}
*/
