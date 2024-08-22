/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:19:21 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 17:02:49 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (ft_list_size(begin_list->next) + 1);
}

void	init_items(t_list **begin_list, t_list **current, t_list **prev,
		t_list **next)
{
	*current = *begin_list;
	*prev = NULL;
	*next = NULL;
}

void	ft_list_sort_2(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	init_items(begin_list, &current, &prev, &next);
	while (current && current->next)
	{
		next = current->next;
		if (cmp(current->data, next->data) > 0)
		{
			current->next = next->next;
			next->next = current;
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			prev = next;
			next = current;
		}
		else
		{
			prev = current;
			current = next;
		}
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int	size;

	size = ft_list_size(*begin_list);
	while (size > 0)
	{
		ft_list_sort_2(begin_list, cmp);
		size--;
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
// 	int		ints[16] = {4, 7, 9, 0, 1, 7, 2, 12, 4, 52, 3, 456, 75, 43, 3};
// 	t_list	*start;
// 	t_list	**list;

// 	ints[15] = 0;
// 	list = &start;
// 	start = ft_list_push_strs(15, ints);
// 	ft_list_foreach(start, print_data);
// 	printf("filtered:\n");
// 	ft_list_sort(list, cmp);
// 	start = *list;
// 	ft_list_foreach(start, print_data);
// }
