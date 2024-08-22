/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:40:10 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 13:22:37 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c < ' ' || c >= 127)
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "fji\1FEWjfw5Wo#";
// 	char src2[] = "FEWfewfr2+FEWF";

// 	printf("string: %s result: %d\n", src, ft_str_is_printable(src));
// 	printf("string: %s result: %d\n", src2, ft_str_is_printable(src2));
// }