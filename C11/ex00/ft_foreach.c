/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:28:01 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 14:30:35 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// #include <stdio.h>

// void	putnbr(int i)
// {
// 	printf("%d\n", i);
// }

// int	main(void)
// {
// 	int list[] = {5, 2, 7, 6, 5};
// 	ft_foreach(list, 5, putnbr);
// }