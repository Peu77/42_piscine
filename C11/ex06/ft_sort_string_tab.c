/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:45:35 by eebert            #+#    #+#             */
/*   Updated: 2024/08/16 11:13:07 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	char			c1;
	char			c2;

	i = 0;
	while (1)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (!c1 && !c2)
			return (0);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

void	ft_sort_words(char **tab, int size)
{
	int		a;
	int		b;
	char	*buffer;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size - a - 1)
		{
			if (ft_strcmp(tab[b], tab[b + 1]) > 0)
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

int	ft_string_array_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	len;

	len = ft_string_array_len(tab);
	ft_sort_words(tab, len);
}

// #include <stdio.h>

// int main(int argc, char** args){
// 	ft_sort_string_tab(args);
// 	for(int i = 0; i < argc; i++){
// 		printf("%s\n", args[i]);
// 	}
// }
