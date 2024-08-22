/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:41:58 by eebert            #+#    #+#             */
/*   Updated: 2024/08/16 11:14:21 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
// void	ft_foreach(char **tab, int length, void (*f)(char*))
// {
// 	int	i;

// 	i = 0;
// 	while (i < length)
// 	{
// 		f(tab[i]);
// 		i++;
// 	}
// }

// #include <stdio.h>

// void	print_str(char *str)
// {
// 	printf("%s\n", str);
// }

// int cmp(char* str){
// 	return str[0] == 'a';
// }

// int	main(void)
// {
// 	char* list[] = {"test", "ahello", "aff"};
// 	ft_foreach(list, 3, print_str);
// 	printf("%d\n", ft_count_if(list, 3, cmp));
// }