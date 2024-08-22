/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:30:51 by eebert            #+#    #+#             */
/*   Updated: 2024/08/15 19:58:43 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*copy;

	copy = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		copy[i] = f(tab[i]);
		i++;
	}
	return (copy);
}

// void	ft_foreach(int *tab, int length, void (*f)(int))
// {
// 	int	i;

// 	i = 0;
// 	while (i < length)
// 	{
// 		f(tab[i]);
// 		i++;
// 	}
// }

// #include <stdio.h>

// void	putnbr(int i)
// {
// 	printf("%d\n", i);
// }

// int	map(int i)
// {
// 	return (i * 2);
// }

// int	main(void)
// {
// 	int list[] = {5, 2, 7, 6, 5};
// 	ft_foreach(list, 5, putnbr);
// 	int *new = ft_map(list, 5, map);
// 	printf("map: \n");
// 	ft_foreach(new, 5, putnbr);
// }