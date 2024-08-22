/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:19:26 by eebert            #+#    #+#             */
/*   Updated: 2024/08/03 14:41:50 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	current_char;

	i = 0;
	while (str[i])
	{
		current_char = str[i];
		if (!((current_char >= 65 && current_char <= 90) || (current_char >= 97
					&& current_char <= 122)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "fjiFEWjfw5Wo#";
// 	printf("string: %s result: %d\n", src, ft_str_is_alpha(src));

// 	char src2[] = "fjifaDFfwWo";
// 	printf("string: %s result: %d\n", src2, ft_str_is_alpha(src2));
// }