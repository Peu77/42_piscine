/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:21:39 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 15:51:48 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **args)
{
	char	*name;

	name = args[0];
	if (argc > 0)
	{
		while (*name)
		{
			write(1, name, 1);
			name++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
