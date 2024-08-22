/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:24:15 by eebert            #+#    #+#             */
/*   Updated: 2024/08/06 17:24:16 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	product;

	product = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		product *= nb;
		power--;
	}
	return (product);
}

// #include <stdio.h>

// int main(){
// 	printf("%d\n", ft_iterative_power(2, 0));
// }