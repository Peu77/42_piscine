/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:50:40 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 19:03:37 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sort_list(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;
	void	*swap;

	current = *begin_list;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (cmp(current->data, tmp->data) > 0)
			{
				swap = current->data;
				current->data = tmp->data;
				tmp->data = swap;
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;

	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != NULL)
		current = current->next;
	current->next = begin_list2;
	ft_sort_list(begin_list1, cmp);
}

// #include <stdio.h>

// void	print_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d ", *(int *)list->data);
// 		list = list->next;
// 	}
// 	printf("\n");
// }

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*elem;

// 	elem = (t_list *)malloc(sizeof(t_list));
// 	if (elem == NULL)
// 		return (NULL);
// 	elem->data = data;
// 	elem->next = NULL;
// 	return (elem);
// }

// t_list	*create_list(int *arr, int size)
// {
// 	t_list	*begin_list;
// 	t_list	*current;
// 	int		i;

// 	begin_list = ft_create_elem(&arr[0]);
// 	current = begin_list;
// 	i = 1;
// 	while (i < size)
// 	{
// 		current->next = ft_create_elem(&arr[i]);
// 		current = current->next;
// 		i++;
// 	}
// 	return (begin_list);
// }

// int	int_cmp(int *a, int *b)
// {
// 	return (*a - *b);
// }

// void	test_ft_sorted_list_merge(void)
// {
// 	int		arr1[] = {1, 3, 5};
// 	int		arr2[] = {2, 4, 6};
// 	t_list	*list1;
// 	t_list	*list2;

// 	list1 = create_list(arr1, 3);
// 	list2 = create_list(arr2, 3);
// 	ft_sorted_list_merge(&list1, list2, int_cmp);
// 	printf("Merged list: ");
// 	print_list(list1);
// }

// int	main(void)
// {
// 	test_ft_sorted_list_merge();
// 	return (0);
// }