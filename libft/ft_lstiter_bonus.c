/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:52:33 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/02 19:51:41 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	del(void *content)
{
	printf("Delete→%s\n", (char *)content);
	free(content);
}

static void	test_func(void *content)
{
	char	*c;
	int		i;

	c = (char *)content;
	if (content == NULL)
		return ;
	i = 0;
	while (c[i])
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] = c[i] - ('a' - 'A');
		else if (c[i] >= 'A' && c[i] <= 'Z')
			c[i] = c[i] + ('a' - 'A');
		i++;
	}
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
int	main(void)
{
	t_list	*first_add;
	t_list	*node1;
	t_list	*node2;

	first_add = NULL;
	node1 = ft_lstnew(ft_strdup("Happy1"));
	node2 = ft_lstnew(ft_strdup("Happy2"));
	ft_lstadd_back(&first_add, node1);
	ft_lstadd_back(&first_add, node2);
	ft_lstiter(first_add, &test_func);
	printf("node1:%s\n", (char *)first_add->content);
	printf("node2:%s\n", (char *)first_add->next->content);
	ft_lstclear(&first_add, del);
}
*/
