/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:19:14 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:15:27 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	buffer;

	i = 0;
	while (i < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = buffer;
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	list[] = {1, 2, 3, 4, 5, 6, 7};

// 	for (int i = 0; i < 7; i++)
// 		printf("%d", list[i]);
// 	printf("\n");
// 	ft_rev_int_tab(list, 7);
// 	for (int i = 0; i < 7; i++)
// 		printf("%d", list[i]);
// }
