/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:07:55 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:10:11 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a = 13;
// 	int b = 5;
// 	int div = 0;
// 	int mod = 0;

// 	printf("a: %d b: %d div: %d mod: %d", a, b, div, mod);
// 	ft_div_mod(a, b, &div, &mod);
// 	printf("a: %d b: %d div: %d mod: %d", a, b, div, mod);
// }