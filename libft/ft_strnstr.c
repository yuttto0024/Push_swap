/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:26:15 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:20:02 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len))
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	big[] = "HappyGoodHappy";
	char	little[] = "Good";
	char	*p;
	size_t	len;

	len = sizeof(big);
	p = ft_strnstr(big, little, len);
	printf("original:%p\n", &big[5]);
	printf("result  :%p\n", p);

	p = ft_strnstr(big, little, 5);
	printf("result:%p\n", p);
}
*/