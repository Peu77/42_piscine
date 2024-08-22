/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:29:50 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 19:34:03 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (ft_list_size(begin_list->next) + 1);
}

// #include <stdio.h>

// int main(){
// 	t_list a;
// 	t_list b;
// 	t_list c;
// 	t_list d;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	printf("%d", ft_list_size(&a));
// }