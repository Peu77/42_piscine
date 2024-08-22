/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:07:22 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 15:15:52 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	int		i;
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	while (current)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			if (*begin_list == current)
				*begin_list = next;
			if (prev)
			{
				prev->next = next;
				free_fct(current->data);
				free(current);
			}
		}
		else
			prev = current;
		current = next;
	}
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

// int	cmp(char *data, char *data_ref)
// {
// 	if (data[0] == data_ref[0])
// 		return (0);
// 	return (1);
// }

// void	free_data(void *test)
// {
// }

// void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
// {
// 	if (begin_list == NULL)
// 		return ;
// 	f(begin_list->data);
// 	ft_list_foreach(begin_list->next, f);
// }

// void	print_data(void *data)
// {
// 	printf("%s\n", data);
// }

// int	main(void)
// {
// 	char	*strs[] = {"test", "test4", "gewg", "8fewf", "1234"};
// 	t_list	*start;
// 	t_list	**list;

// 	list = &start;
// 	start = ft_list_push_strs(5, strs);
// 	ft_list_foreach(start, print_data);
// 	printf("filtered:\n");
// 	ft_list_remove_if(list, "8", cmp, free_data);
// 	start = *list;
// 	ft_list_foreach(start, print_data);
// }
