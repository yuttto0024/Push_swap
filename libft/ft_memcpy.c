/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:33:24 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/03 15:38:00 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n > 0 && (dest == NULL && src == NULL))
		return (NULL);
	i = 0;
	while (n > i)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char	*src = NULL;
// 	char	*dest1 = NULL; 
// 	char	*dest2 = NULL;
// 	size_t	i;	
// 	i = 7;
//
// 	printf("---memset---\n");
// 	memcpy(dest1, src, i);
// 	printf("%s\n", dest1);
// 	// printf("---ft_memset---\n");
//     // ft_memcpy(dest2, src, i);
// 	// printf("%s\n", dest2);
// 	return (0);
// }
