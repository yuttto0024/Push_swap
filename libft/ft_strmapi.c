/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:33:22 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/30 16:33:22 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	ft_test_function(unsigned int i, char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' -  'A'));
	if (c >= 'a' && c <= 'z')
		return (c - ('a' -  'A'));
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	size_t			len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}

/*
int	main(void)
{
	char	*p;
	char	str[] = "Happy";

	p = ft_strmapi(str, &ft_test_function);
	printf("Before:%s\n", str);
	printf("After :%s\n", p);
	free(p);
	return (0);
}
*/