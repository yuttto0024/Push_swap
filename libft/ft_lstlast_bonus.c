/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:26:05 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:18:55 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last_add;

	first_add = NULL;
	node1 = ft_lstnew("Happy1\n");
	node2 = ft_lstnew("Happy2\n");
	node3 = ft_lstnew("Last\n");
	ft_lstadd_front(&first_add, node3);
	ft_lstadd_front(&first_add, node2);
	ft_lstadd_front(&first_add, node1);
	last_add = ft_lstlast(first_add);
	printf("%s", (char *)last_add->content);
}
*/