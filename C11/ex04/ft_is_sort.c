/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:43:40 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 15:01:31 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	i = 0;
	asc = 1;
	desc = 1;
	while (++i < length && (asc || desc))
	{
		if (f(tab[i - 1], tab[i]) < 0)
			desc = 0;
		else if (f(tab[i - 1], tab[i]) > 0)
			asc = 0;
	}
	return (asc || desc);
}

// int	is_higher(int a, int b)
// {
// 	if (a > b)
// 		return (-1);
// 	if (a < b)
// 		return (1);
// 	return (0);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int list[] = {7, 8, 5, 4};
// 	printf("is_sort: %d", ft_is_sort(list, 4, is_higher));
// }