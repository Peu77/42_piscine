/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:23:13 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 23:32:58 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_start;

	new_start = ft_create_elem(data);
	if (*begin_list)
	{
		new_start->next = *begin_list;
		*begin_list = new_start;
	}
	else
		*begin_list = new_start;
}
