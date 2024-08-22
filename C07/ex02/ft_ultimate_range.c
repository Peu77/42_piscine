/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:36:15 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 21:05:49 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	*list;
	int	i;

	i = 0;
	diff = max - min;
	list = (int *)malloc((diff + 1) * sizeof(int));
	if (min >= max || list == 0)
	{
		*range = 0;
		return (0);
	}
	while (min < max)
	{
		list[i] = min;
		i++;
		min++;
	}
	list[i] = 0;
	*range = list;
	return (diff);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	r[5];
// 	int	**s;

// 	s = &r;
// 	printf("%d", ft_ultimate_range(s, 1, 2));
// }
