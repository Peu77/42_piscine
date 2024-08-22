/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:27:11 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:33:23 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	buffer;

	a = 0;
	b = 0;
	while (a < size)
	{
		b = 0;
		while (b < size - a - 1)
		{
			if (tab[b] > tab[b + 1])
			{
				buffer = tab[b];
				tab[b] = tab[b + 1];
				tab[b + 1] = buffer;
			}
			b++;
		}
		a++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	list[] = {5, 7, 2, 3, 1, 6, 9, 5};

// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d", list[i]);
// 	}
// 	ft_sort_int_tab(list, 8);
// 	printf("\n");
// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d", list[i]);
// 	}
// }
