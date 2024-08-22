/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:51:25 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 13:45:14 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*current;
	t_list	*new_item;
	int		i;

	i = 0;
	current = ft_create_elem(strs[i]);
	i++;
	while (i < size)
	{
		new_item = ft_create_elem(strs[i]);
		new_item->next = current;
		current = new_item;
		i++;
	}
	return (current);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	item->data = data;
	item->next = NULL;
	return (item);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *strs[] = {"test", "fwfwf", "gwgw4fw", "fewf", "1234"};
// 	t_list *start = ft_list_push_strs(5, strs);
// 	printf("%s\n", start->data);
// 	printf("%s\n", start->next->data);
// 	printf("%s\n", start->next->next->data);
// 	printf("%s\n", start->next->next->next->data);
// 	printf("%s\n", start->next->next->next->next->data);
// }
