/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:53:15 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:48:24 by yuonishi         ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	first_add = NULL;
	node1 = ft_lstnew(ft_strdup("Happy1"));
	node2 = ft_lstnew(ft_strdup("Happy2"));
	node3 = ft_lstnew(ft_strdup("Happy3"));
	ft_lstadd_front(&first_add, node3);
	ft_lstadd_front(&first_add, node2);
	ft_lstadd_front(&first_add, node1);
	ft_lstclear(&first_add, del);

	if (first_add == NULL)
		printf("Success\n");
	else
		printf("Failed\n");
	return (0);
}
*/