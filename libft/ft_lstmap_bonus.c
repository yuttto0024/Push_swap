/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:43:25 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:18:57 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	del(void *content)
{
	printf("Delete→ %s\n", (char *)content);
	free(content);
}

static void	*test_func(void *content)
{
	return (ft_strdup("HappyHappy"));
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_first_add;
	t_list	*new_node;
	void	*new_content;

	new_first_add = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_first_add, del);
			return (NULL);
		}
		ft_lstadd_back(&new_first_add, new_node);
		lst = lst->next;
	}
	return (new_first_add);
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*new_first_add;
	t_list	*node1;
	t_list	*node2;	
	t_list	*node3;
	
	first_add = NULL;
	node1 = ft_lstnew(ft_strdup("Happy1"));
	node2 = ft_lstnew(ft_strdup("Happy2"));
	node3 = ft_lstnew(ft_strdup("Happy3"));
	ft_lstadd_back(&first_add, node1);
	ft_lstadd_back(&first_add, node2);
	ft_lstadd_back(&first_add, node3);
	printf("node1:%s\n", (char *)first_add->content);
	printf("node2:%s\n", (char *)first_add->next->content);
	printf("node3:%s\n", (char *)first_add->next->next->content);
	new_first_add = ft_lstmap(first_add, &test_func, del);
	printf("new_node1:%s\n", (char *)new_first_add->content);
	printf("new_node2:%s\n", (char *)new_first_add->next->content);
	printf("new_node3:%s\n", (char *)new_first_add->next->next->content);
	ft_lstclear(&first_add, del);
	ft_lstclear(&new_first_add, del);
	return (0);
}
*/
