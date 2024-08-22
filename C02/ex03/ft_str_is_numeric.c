/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:32:50 by eebert            #+#    #+#             */
/*   Updated: 2024/08/03 14:43:49 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c < '0' || c > '9')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "fjiFEWjfw5Wo#";
// 	char	src2[] = "123456";

// 	printf("string: %s result: %d\n", src, ft_str_is_numeric(src));
// 	printf("string: %s result: %d\n", src2, ft_str_is_numeric(src2));
// }
