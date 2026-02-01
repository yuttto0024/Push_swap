/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:58:39 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:48:03 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	del(void *content)
{
	printf("Delete→%s\n", (char *)content);
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
int	main(void)
{
	t_list	*node1;
	char	*content;

	content = ft_strdup("HappyHappy");
	if (content == NULL)
		return (1);
	node1 = ft_lstnew(content);
	if (node1 == NULL)
	{
		free(content);
		return (1);
	}
	ft_lstdelone(node1, &del);
	printf("complete\n");
	return (0);
}
*/