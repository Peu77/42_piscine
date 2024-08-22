/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:12:15 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:11:20 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_result;
	int	mod_result;

	div_result = *a / *b;
	mod_result = *a % *b;
	*a = div_result;
	*b = mod_result;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a = 13;
// 	int b = 5;

// 	printf("a: %d b: %d", a, b);
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("a: %d b: %d", a, b);
// }