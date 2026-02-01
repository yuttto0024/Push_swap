/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:22:32 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:48:32 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_add;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_add = ft_lstlast(*lst);
	last_add->next = new;
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*last_add;

	first_add = NULL;
	node1 = ft_lstnew("Happy1");
	node2 = ft_lstnew("Happy2");
	node3 = ft_lstnew("Happy3");
	node4 = ft_lstnew("last");
	ft_lstadd_front(&first_add, node1);
	ft_lstadd_front(&first_add, node2);
	ft_lstadd_front(&first_add, node3);
	ft_lstadd_back(&first_add, node4);
	last_add = ft_lstlast(first_add);
	printf("%s\n", (char *)last_add->content);
	free(first_add->next->next->next);
	free(first_add->next->next);
	free(first_add->next);
	free(first_add);
}
*/