/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:19:34 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 22:24:35 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = ft_strlen(s);
	if ((unsigned char)s[len] == uc)
		return ((char *)&s[len]);
	while (len > 0)
	{
		len--;
		if ((unsigned char)s[len] == uc)
			return ((char *)&s[len]);
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Happy new year";
	char	*result;
	int		search;
	int		deference;

	search = 'y';
	printf("---strrchr---\n");
	result = strrchr(str, search);
	printf("Address: %p\n", result);
	printf("---ft_strrchr---\n");
	result = ft_strrchr(str, search);
	printf("Address: %p\n", result);
	deference = strrchr(str, search) - ft_strrchr(str, search);
	printf("deference: %d\n", deference);
}
*/