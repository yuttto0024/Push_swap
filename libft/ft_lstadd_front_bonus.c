/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:18:12 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:48:30 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;

	first_add = NULL;
	node1 = ft_lstnew("Happy1");
	node2 = ft_lstnew("Happy2");
	ft_lstadd_front(&first_add, node1);
	printf("node1:%s\n", (char *)first_add->content);
	ft_lstadd_front(&first_add, node2);
	printf("node2:%s\n", (char *)first_add->content);
	if (first_add == node2 && first_add->next == node1)
		printf("Linked node2->node1\n");
	free(first_add->next);
	free(first_add);
	return (0);
}
*/