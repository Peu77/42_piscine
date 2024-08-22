/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:04:19 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 15:15:10 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		a;
	int		b;
	char	*buffer;
	int		size;

	size = 0;
	while (tab[size])
		size++;
	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size - a - 1)
		{
			if (cmp(tab[b], tab[b + 1]) > 0)
			{
				buffer = tab[b];
				tab[b] = tab[b + 1];
				tab[b + 1] = buffer;
			}
			b++;
		}
		a++;
	}
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	unsigned int	i;
// 	char			c1;
// 	char			c2;

// 	i = 0;
// 	while (1)
// 	{
// 		c1 = s1[i];
// 		c2 = s2[i];
// 		if (!c1 && !c2)
// 			return (0);
// 		if (c1 != c2)
// 			return (c1 - c2);
// 		i++;
// 	}
// 	return (0);
// }

// #include <stdio.h>

// int	main(int argc, char **args)
// {
// 	t_advanced_sort_string_tab(args, ft_strcmp);
// 	for (int i = 0; i < argc; i++)
// 	{
// 		printf("%s\n", args[i]);
// 	}
// }
