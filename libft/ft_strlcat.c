/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:31:57 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 16:00:40 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	init_dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	init_dest_len = 0;
	while (dest[init_dest_len] && (init_dest_len < size))
		init_dest_len++;
	if (init_dest_len == size)
		return (init_dest_len + src_len);
	i = 0;
	while (src[i] && init_dest_len + i < size - 1)
	{
		dest[init_dest_len + i] = src[i];
		i++;
	}
	dest[init_dest_len + i] = '\0';
	return (init_dest_len + src_len);
}

/*
int	main(void)
{
	char	dest[10] = "Happy";
	char	src[] = "World";
	size_t	buff_size;
	size_t	return_len;

	buff_size = sizeof(dest);
	return_len = ft_strlcat(dest, src, buff_size);
	printf("dest:%s\n", dest);
	printf("len:%zu\n", return_len);
}
*/