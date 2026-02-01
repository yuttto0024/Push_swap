/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:44:52 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:46 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*
int	main(void)
{
	char	src[] = "Happy";
	char	dest[5];
	size_t	buff_size;
	size_t	return_len;

	buff_size = sizeof(dest);

	printf("---ft_strlcpy---\n");
	return_len = ft_strlcpy(dest, src, buff_size);
	printf("dest:%s\n", dest);
	printf("len:%zu\n", return_len);
}
*/