/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:06:15 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:08:01 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a;
// 	int b;

// 	a = 5;
// 	b = 7;

// printf("a %d b: %d", a, b);
// 	ft_swap(&a, &b);
// 	printf("a %d b: %d", a, b);
// }