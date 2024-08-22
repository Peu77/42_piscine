/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:03:22 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 19:12:37 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

// 1 -> 2 -> 3 -> 4 -> 5
// 5 -> 4 -> 3 -> 2 -> 1

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (ft_list_size(begin_list->next) + 1);
}

void	swap_at_index(t_list *item, t_list *current, int i)
{
	void	*swap;

	if (current == NULL)
		return ;
	if (i == 0)
	{
		swap = current->data;
		current->data = item->data;
		item->data = swap;
		return ;
	}
	swap_at_index(item, current->next, i - 1);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*current;

	size = ft_list_size(begin_list);
	i = 0;
	current = begin_list;
	while (i < size / 2)
	{
		swap_at_index(current, begin_list, size - 1 - i);
		current = current->next;
		i++;
	}
}

// t_list	*ft_list_push_strs(int size, int *ints)
// {
// 	t_list	*current;
// 	t_list	*new_item;
// 	int		i;

// 	i = 0;
// 	current = ft_create_elem(&ints[i]);
// 	i++;
// 	while (i < size)
// 	{
// 		new_item = ft_create_elem(&ints[i]);
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

// void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
// {
// 	if (begin_list == NULL)
// 		return ;
// 	f(begin_list->data);
// 	ft_list_foreach(begin_list->next, f);
// }

// void	print_data(void *data)
// {
// 	int	*i;

// 	i = (int *)data;
// 	printf("%d\n", *i);
// }

// int	cmp(int *a, int *b)
// {
// 	return (*a > *b);
// }

// int	main(void)
// {
// 	int		ints[16] = {1, 2, 3, 4, 5, 6, 7};
// 	t_list	*start;
// 	t_list	**list;

// 	ints[7] = 0;
// 	list = &start;
// 	start = ft_list_push_strs(7, ints);
// 	ft_list_foreach(start, print_data);
// 	printf("rev:\n");
// 	ft_list_reverse_fun(start);
// 	start = *list;
// 	ft_list_foreach(start, print_data);
// }
