/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:44:28 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 21:48:26 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, len + 1);
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "HappyHappy";
	char	*s;

	printf("---strdup---\n");
	s = strdup(src);
	printf("%s\n", s);
	free(s);
	printf("---strdup---\n");
	s = ft_strdup(src);
	printf("%s\n", s);
	free(s);
}
*/