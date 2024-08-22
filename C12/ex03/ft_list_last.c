/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:39:54 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 19:42:13 by eebert           ###   ########.fr       */
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

// #include <stdio.h>

// int main(){
// 	t_list a;
// 	t_list b;
// 	t_list c;
// 	t_list d;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	printf("%d", &d == ft_list_last(&a));
// }