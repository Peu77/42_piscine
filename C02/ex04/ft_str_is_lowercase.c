/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:36:47 by eebert            #+#    #+#             */
/*   Updated: 2024/08/03 14:46:39 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c < 'a' || c > 'z')
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "fjiFEWjfw5Wo#";
// 	char src2[] = "fewfewfgewg";

// 	printf("string: %s result: %d\n", src, ft_str_is_lowercase(src));
// 	printf("string: %s result: %d\n", src2, ft_str_is_lowercase(src2));
// }