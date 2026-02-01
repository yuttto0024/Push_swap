/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:02:29 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/30 18:02:29 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	int	fd;

	fd = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_putchar_fd('C', fd);
	close(fd);
	return (0);
}
*/