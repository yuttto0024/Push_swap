/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:52:15 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:07:22 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int		result;
	size_t	i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	const char	*test_str;

// 	test_str = "+42";
// 	printf("ft_atoi:%d\n", ft_atoi(test_str));
// 	printf("atoi   :%d\n", atoi(test_str));

// 	test_str = "+4242pp4242";
// 	printf("ft_atoi:%d\n", ft_atoi(test_str));
// 	printf("atoi   :%d\n", atoi(test_str));

// 	test_str = "-2147483648";
// 	printf("ft_atoi:%d\n", ft_atoi(test_str));
// 	printf("atoi   :%d\n", atoi(test_str));

// 	test_str = "-2147483649";
// 	printf("ft_atoi:%d\n", ft_atoi(test_str));
// 	printf("atoi   :%d\n", atoi(test_str));

// 	test_str = "    \n\t\v\f\r-123 456";
// 	printf("ft_atoi:%d\n", ft_atoi(test_str));
// 	printf("atoi   :%d\n", atoi(test_str));
// }
