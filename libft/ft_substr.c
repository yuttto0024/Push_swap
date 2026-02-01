/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:15:59 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 19:27:25 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_empty_str(void)
{
	char	*sub_str;

	sub_str = (char *)malloc(1);
	if (sub_str == NULL)
		return (NULL);
	sub_str[0] = '\0';
	return (sub_str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	str_len;
	char	*sub_str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_alloc_empty_str());
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	sub_str = (char *)malloc(size + 1);
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (size > i)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

/*
int	main(void)
{
	const char		src[] = "HappyHoliday";
	unsigned int	start;
	size_t			len;
	char			*p;

	start = 5;
	len = 7;
	p = ft_substr(src, start, len);
	printf("%s", p);
	free(p);
}
*/
