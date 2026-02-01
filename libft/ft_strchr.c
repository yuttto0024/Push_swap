/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:21:05 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 21:44:58 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "teste";
	char	*result;
	int		search;

	search = 'e';
	printf("---strchr---\n");
	result = strchr(str, search);
	printf("Address: %p\n", result);

	printf("---ft_strchr---\n");
	result = ft_strchr(str, search);
	printf("Address: %p\n", result);
}
*/
