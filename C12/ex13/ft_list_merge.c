/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:17:20 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 15:18:58 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*item;

	item = ft_list_last(*begin_list1);
	if (item)
		item->next = begin_list2;
}
