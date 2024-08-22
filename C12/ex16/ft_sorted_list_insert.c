/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:46:02 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 18:57:05 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*new;

	current = *begin_list;
	new = ft_create_elem(data);
	if (current == NULL || cmp(current->data, data) > 0)
	{
		new->next = current;
		*begin_list = new;
		return ;
	}
	while (current->next != NULL && cmp(current->next->data, data) < 0)
		current = current->next;
	new->next = current->next;
	current->next = new;
}

t_list	*ft_list_push_strs(int size, int *ints)
{
	t_list	*begin_list;
	t_list	*current;
	int		i;

	begin_list = ft_create_elem(&ints[0]);
	current = begin_list;
	i = 1;
	while (i < size)
	{
		current->next = ft_create_elem(&ints[i]);
		current = current->next;
		i++;
	}
	return (begin_list);
}

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

// int	ft_strcmp(void *s1, void *s2)
// {
// 	return (*(int *)s1 - *(int *)s2);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*begin_list;
// 	int		ints[5] = {1, 2, 3, 4, 5};
// 	int		i;

// 	begin_list = ft_list_push_strs(5, ints);
// 	ft_sorted_list_insert(&begin_list, &ints[4], &ft_strcmp);
// 	i = 0;
// 	while (begin_list != NULL)
// 	{
// 		printf("%d\n", *(int *)begin_list->data);
// 		begin_list = begin_list->next;
// 	}
// 	return (0);
// }
