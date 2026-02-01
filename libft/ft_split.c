/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:10:06 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 18:16:15 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			wc++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (wc);
}

static void	*free_all(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	return (NULL);
}

static char	**ft_fill_array(char const *s, char c, char **p, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	start;

	i = 0;
	j = 0;
	while (wc > i)
	{
		while (s[j] == c)
			j++;
		start = j;
		len = 0;
		while (s[j] && s[j] != c)
		{
			j++;
			len++;
		}
		p[i] = ft_substr(&s[start], 0, len);
		if (p[i] == NULL)
			return (free_all(p, i));
		i++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	size_t			wc;

	if (s == NULL)
		return (NULL);
	wc = ft_word_count(s, c);
	p = (char **)ft_calloc(wc + 1, sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (ft_fill_array(s, c, p, wc));
}

/*
int	main(void)
{
	char	test[] = "This-Happy-pen------";
	char	c;
	char	**t;
	size_t	i;

	c = '-';
	t = ft_split(test, c);
	i = 0;
	while (t[i]) 
	{
		printf("%s\n", t[i]);
		i++;
	}
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}
*/
