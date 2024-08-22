/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:45:20 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 15:13:36 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	if (nb < 0)
		return (0);
	i = 0;
	while (i <= 46340)
	{
		sqrt = i * i;
		if (sqrt == nb)
			return (i);
		if (sqrt > nb)
			return (0);
		if (sqrt < 0)
			return (0);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_sqrt(1716880216));
// }