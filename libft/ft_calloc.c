/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:25:50 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:07:59 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	p = (void *)malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, total_size);
	return (p);
}

/*
int	main(void)
{
	int		*p;

	p = ft_calloc(SIZE_MAX, 2);
	if (p != NULL)
		printf("Failed1\n");
	else
	{
		printf("ft_calloc returned NULL by overflow\n");
		free(p);
	}
	p = ft_calloc(5, 0);
	if (p == NULL)
		printf("Failed2\n");
	else
	{
		printf("Returned a valid p\n");
		free(p);
	}
	p = ft_calloc(5, 0);
	if (p == NULL)
		printf("Failed3\n");
	else
	{
		printf("Returned a valid p\n");
		free(p);
	}
	return (0);
}
*/
