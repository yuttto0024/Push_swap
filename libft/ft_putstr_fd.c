/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:08:35 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/30 18:08:35 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
int	main(void)
{
	int		fd;
	char	str[] = "HappyHappy";

	fd = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_putstr_fd(str, fd);
	close(fd);
	return (0);
}
*/