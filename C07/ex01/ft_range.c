/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:10:59 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 19:49:49 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	diff;
	int	*list;
	int	i;

	i = 0;
	diff = max - min;
	if (min >= max)
		return (0);
	list = (int *)malloc((diff + 1) * sizeof(int));
	if (list == 0)
		return (0);
	while (min < max)
	{
		list[i] = min;
		i++;
		min++;
	}
	list[i] = 0;
	return (list);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	*list = ft_range(-5, 5);

// 	// list = ft_range(-5, 5);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", list[i]);
// 	}
// }
