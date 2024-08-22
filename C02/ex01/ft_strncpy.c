/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:09:13 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 13:03:19 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <memory.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// int	random_in_range(int range)
// {
// 	srand(time(NULL));
// 	return ((random() % range) + 1);
// }

// char	*random_string(int size)
// {
// 	char	*string;
// 	char	random_char;

// 	string = malloc((size + 1) * sizeof(char));
// 	for (int i = 0; i < size; i++)
// 	{
// 		random_char = random_in_range(50) + 'A';
// 		string[i] = random_char;
// 	}
// 	return (string);
// }

// int	main(void)
// {
// 	for (int i = -100; i < 100; i++)
// 	{
// 		printf("i: %d\n", i);
// 		char *src = random_string(random_in_range(20));

// 		int dest_size = random_in_range(20);
// 		char *dest = random_string(dest_size + 20);
// 		char *dest2 = malloc((dest_size + 21) * sizeof(char));

// 		strcpy(dest2, dest);

// 		int copy_size = random_in_range(20);

// 		printf("before: src: %s dest1: %s dest2: %s size: %d\n", src, dest,
// 			dest2, copy_size);

// 		char *a = ft_strncpy(dest, src, copy_size);
// 		char *b = ft_strncpy(dest2, src, copy_size);

// 		int passed = strcmp(dest, dest2) == 0 && strcmp(a, b) == 0;

// 		printf("src: %s dest1: %s dest2: %s size: %d a: %s, b: %s, passed:
// 				%d\n ", src, dest,
// 						dest2,
// 					copy_size,
// 					a,
// 					b,
// 					passed);

// 		if (!passed)
// 			break ;
// 	}

// 	return (0);
// }