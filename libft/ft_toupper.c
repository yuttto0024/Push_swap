/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:30:28 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:20:18 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
/*
int	main(void)
{
	int	i;
	int	j;
	int	l;

	i = 'a';
	j = '0';
	printf("---toupper---\n");
	l = toupper(i);
	printf("%d ~> %d\n", i, l);
	l = toupper(j);
	printf("%d ~> %d\n", j, l);

	printf("---ft_toupper---\n");
	l = ft_toupper(i);
	printf("%d ~> %d\n", i, l);
	l = ft_toupper(j);
	printf("%d ~> %d\n", j, l);
}
*/
