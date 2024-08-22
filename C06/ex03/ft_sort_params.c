/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:35:04 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 15:53:04 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		b = 1;
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

int	main(int argc, char **args)
{
	int		i;
	char	*arg;

	ft_sort_words(args, argc);
	i = 1;
	while (i < argc)
	{
		arg = args[i];
		while (*arg)
		{
			write(1, arg, 1);
			arg++;
		}
		write(1, "\n", 1);
		i++;
	}
}
