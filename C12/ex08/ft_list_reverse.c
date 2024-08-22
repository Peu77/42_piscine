/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:21:52 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 13:45:19 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_list
// {
// 	void			*data;
// 	struct s_list	*next;
// }					t_list;

// t_list				*ft_create_elem(void *data);

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

// t_list	*ft_list_push_strs(int size, char **strs)
// {
// 	t_list	*current;
// 	t_list	*new_item;
// 	int		i;

// 	i = 0;
// 	current = ft_create_elem(strs[i]);
// 	i++;
// 	while (i < size)
// 	{
// 		new_item = ft_create_elem(strs[i]);
// 		new_item->next = current;
// 		current = new_item;
// 		i++;
// 	}
// 	return (current);
// }

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*item;

// 	item = (t_list *)malloc(sizeof(t_list));
// 	item->data = data;
// 	item->next = NULL;
// 	return (item);
// }

// int	main(void)
// {
// 	char	*strs[] = {"test", "gewgw", "gw", "fewf", "1234"};
// 	t_list	*start;
// 	t_list **list = &start;

// 	start = ft_list_push_strs(5, strs);
// 	printf("%s\n", start->data);
// 	printf("%s\n", start->next->data);
// 	printf("%s\n", start->next->next->data);
// 	printf("%s\n", start->next->next->next->data);
// 	printf("%s\n", start->next->next->next->next->data);
// 	printf("rev:\n");
// 	ft_list_reverse(list);
// 	start = *list;
// 	printf("%s\n", start->data);
// 	printf("%s\n", start->next->data);
// 	printf("%s\n", start->next->next->data);
// 	printf("%s\n", start->next->next->next->data);
// 	printf("%s\n", start->next->next->next->next->data);
// }
