/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:08:28 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 12:33:22 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	current_char;

	current_char = 'z';
	while (current_char >= 'a')
	{
		write(1, &current_char, 1);
		current_char--;
	}
}

// int	main(void)
// {
// 	ft_print_reverse_alphabet();
// }
