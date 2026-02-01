/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:42:17 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:57 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((int)(unsigned char)*s1 - (int)(unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
int	main(void)
{
	char	s1[] = "Happy";
	char	s2[] = "Happy2";

	printf("---strncmp---\n");
	printf("%d\n", strncmp(s1, s2, 6));
	printf("%d\n", strncmp(s1, s2, 0));
	printf("---ft_strncmp---\n");
	printf("%d\n", ft_strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp(s1, s2, 0));
}
*/