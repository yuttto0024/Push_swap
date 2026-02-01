/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:39:20 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 22:04:52 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start_index(char const *s1, char const *set)
{
	size_t	start;
	char	*p;

	start = 0;
	while (s1[start])
	{
		p = ft_strchr(set, s1[start]);
		if (p == NULL)
			break ;
		start++;
	}
	return (start);
}

static size_t	get_end_index(char const *s1, char const *set, size_t start)
{
	size_t	end;
	char	*p;

	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (end > start)
	{
		p = ft_strchr(set, s1[end]);
		if (p == NULL)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	trim_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = get_start_index(s1, set);
	if (s1[start] == '\0')
		return (ft_calloc(1, sizeof(char)));
	end = get_end_index(s1, set, start);
	trim_len = (end - start) + 1;
	trim = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_memcpy(trim, s1 + start, trim_len);
	return (trim);
}

/*
int	main(void)
{
	char	s1[] = "-abHappyaab";
	char	*set = NULL;
	char	*trim;

	trim = ft_strtrim(s1, set);
	printf("%s", trim);
	free(trim);
}
*/
