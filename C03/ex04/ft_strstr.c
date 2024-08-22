/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:36:24 by eebert            #+#    #+#             */
/*   Updated: 2024/08/05 17:05:17 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	asign_pointer_if_null(char **ptr_to_ptr, void *value)
{
	if (*ptr_to_ptr == 0)
	{
		*ptr_to_ptr = value;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr_to_first_found;
	char	*start_find_ptr;

	start_find_ptr = to_find;
	ptr_to_first_found = 0;
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			asign_pointer_if_null(&ptr_to_first_found, str);
			if (!*(to_find + 1))
				break ;
			str++;
			to_find++;
			continue ;
		}
		to_find = start_find_ptr;
		ptr_to_first_found = 0;
		str++;
	}
	if (*(to_find + 1))
		return (0);
	return (ptr_to_first_found);
}

// int	main(void)
// {
// 	char	*test;
// 	char	*find;
// 	char	*first;

// 	test = "42 1337 Network 2021 piscine Benguerir Khouribga";
// 	find = "abcd";
// 	first = ft_strstr(test, find);
// 	if (first == 0)
// 	{
// 		printf("not found\n");
// 		return (-1);
// 	}
// 	printf("got %s\n", first);
// 	return (0);
// }
