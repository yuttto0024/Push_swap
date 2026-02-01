/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:37:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:19:01 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	first_add = NULL;
	node1 = ft_lstnew("Happy1");
	node2 = ft_lstnew("Happy2");
	node3 = ft_lstnew("Happy3");
	ft_lstadd_front(&first_add, node3);
	ft_lstadd_front(&first_add, node2);
	ft_lstadd_front(&first_add, node1);
	printf("node_len:%d\n", ft_lstsize(first_add));
	free(first_add->next->next);
	free(first_add->next);
	free(first_add);
}
*/