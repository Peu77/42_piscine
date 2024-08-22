/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:55:36 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 12:57:41 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_length;

	i = 0;
	src_length = 0;
	while (src[src_length])
	{
		src_length++;
	}
	while (src[i] && i < size - 1 && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = 0;
		i++;
	}
	return (src_length);
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

// 		int a =	strlcpy(dest, src, copy_size);
// 		int b =	ft_strlcpy(dest2, src, copy_size);

// 		int passed = strcmp(dest, dest2) == 0 && a == b;

// 		printf("src: %s dest1: %s dest2: %s size: %d a: %d, b: %d, passed:
//			%d\n", src, dest,
// 			dest2, copy_size,a, b, passed);

// 		if (!passed)
// 			break ;
// 	}

// 	return (0);
// }