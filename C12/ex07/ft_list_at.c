/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:15:24 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 13:45:16 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL)
		return (NULL);
	if (nbr <= 0)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list a;
// 	t_list b;
// 	t_list c;
// 	t_list d;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	printf("%d\n", &a == ft_list_at(&a, 0));
// 	printf("%d\n", &b == ft_list_at(&a, 1));
// 	printf("%d\n", &c == ft_list_at(&a, 2));
// 	printf("%d\n", &d == ft_list_at(&a, 3));
// }