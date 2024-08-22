/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:39:00 by eebert            #+#    #+#             */
/*   Updated: 2024/08/03 16:29:12 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c < 'A' || c > 'Z')
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "fjiFEWjfw5Wo#";
// 	char src2[] = "FEWFEWF";

// 	printf("string: %s result: %d\n", src, ft_str_is_uppercase(src));
// 	printf("string: %s result: %d\n", src2, ft_str_is_uppercase(src2));
// }