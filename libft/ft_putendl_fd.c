/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:38:40 by yuonishi          #+#    #+#             */
/*   Updated: 2025/10/30 18:38:40 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int	main(void)
{
	int		fd;
	char	str[] = "Happy";

	fd = open("test3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	ft_putendl_fd(str, fd);
	close(fd);
	return (0);
}
*/