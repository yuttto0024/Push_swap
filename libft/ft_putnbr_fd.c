/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:06:04 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:24 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnb(int n, int fd)
{
	int	i;

	if (n >= 10)
		ft_printnb(n / 10, fd);
	i = (n % 10) + '0';
	ft_putchar_fd(i, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -1 * n;
	}
	ft_printnb(n, fd);
}

/*
int	main(void)
{
	int	n;
	int	fd;

	n = -123456789;
	fd = open("test4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
}
*/