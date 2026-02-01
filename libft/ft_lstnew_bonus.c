/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:27:21 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/01 20:18:59 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
int	main(void)
{
	char	my_content[] = "Test_string";	
	t_list	*new_node;

	new_node = ft_lstnew(my_content);
	if (new_node == NULL)
	{
		printf("Error1\n");
		return (1);
	}
	if (new_node->content == my_content)
		printf("%s\n", (char *)new_node->content);
	else
		printf("Error2\n");
	if (new_node->next == NULL)
		printf("NULL_OK\n");
	else
		printf("Error3\n");
	free(new_node);
	return (0);
}
*/