/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:54:25 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 12:33:17 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	current_char;

	current_char = 'a';
	while (current_char <= 'z')
	{
		write(1, &current_char, 1);
		current_char++;
	}
}

// int	main(void)
// {
// 	ft_print_alphabet();
// }
