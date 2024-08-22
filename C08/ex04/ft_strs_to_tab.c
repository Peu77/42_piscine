/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:52:22 by eebert            #+#    #+#             */
/*   Updated: 2024/08/12 21:06:31 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*create_copy(char *str, int len)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*list;

	i = 0;
	list = malloc((ac + 1) * sizeof(t_stock_str));
	list[ac].str = 0;
	while (i < ac)
	{
		if (!av[i])
		{
			return (0);
		}
		list[i].size = ft_strlen(av[i]);
		list[i].str = av[i];
		list[i].copy = create_copy(av[i], list[i].size);
		i++;
	}
	return (list);
}
