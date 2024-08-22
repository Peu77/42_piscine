/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:29:52 by eebert            #+#    #+#             */
/*   Updated: 2024/08/05 14:27:37 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	write_index;
	unsigned int	read_index;

	write_index = 0;
	read_index = 0;
	while (dest[write_index])
		write_index++;
	while (src[read_index])
	{
		dest[write_index] = src[read_index];
		write_index++;
		read_index++;
	}
	dest[write_index] = 0;
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
// 	string[size] = 0;
// 	return (string);
// }

// void	test_strings(char *src, char *dest)
// {
// 	int		passed;
// 	int		dest_len;
// 	int		src_len;
// 	char	*dest1;
// 	char	*dest2;

// 	dest_len = strlen(dest);
// 	src_len = strlen(src);
// 	dest1 = malloc((dest_len + src_len + 1) * sizeof(char));
// 	dest2 = malloc((dest_len + src_len + 1) * sizeof(char));
// 	strcpy(dest1, dest);
// 	strcpy(dest2, dest);
// 	strcat(dest1, src);
// 	ft_strcat(dest2, src);
// 	printf("dest1: %s\n", dest1);
// 	printf("dest2: %s\n", dest2);
// 	passed = strcmp(dest1, dest2) == 0;
// 	strdup(dest1);
// 	strdup(dest2);
// 	strdup(src);
// 	strdup(dest);
// 	printf("passed: %d\n", passed);
// 	if (!passed)
// 		exit(-1);
// }

// int	main(void)
// {
// 	char	*src;
// 	char	*dest;

// 	for (int i = -100; i < 100; i++)
// 	{
// 		src = random_string(random_in_range(10));
// 		dest = random_string(random_in_range(10));
// 		test_strings(src, dest);
// 	}
// 	test_strings("abcdef", "abcdefg");
// 	test_strings("abcdefg", "abcdef");
// 	test_strings("", "");

// 	return (0);
// }
