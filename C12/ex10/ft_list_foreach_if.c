/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:33:36 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 00:05:15 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return ;
	if (cmp(begin_list->data, data_ref) == 0)
	{
		f(begin_list->data);
	}
	ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}
