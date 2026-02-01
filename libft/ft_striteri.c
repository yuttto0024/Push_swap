/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:31:26 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/30 17:31:26 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_test_function(unsigned int i, char *p)
{
	if (i % 2 == 0)
		*p = 'Z';
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	str[] = "Happy";

	printf("Before:%s\n", str);
	ft_striteri(str, &ft_test_function);
	printf("After :%s\n", str);
	return (0);
}
*/