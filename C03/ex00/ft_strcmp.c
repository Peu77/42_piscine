/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:39:50 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 14:06:13 by eebert           ###   ########.fr       */
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

// void	test_strings(char *c1, char *c2)
// {
// 	int	passed;
// 	int	result1;
// 	int	result2;

// 	result1 = strcmp(c1, c2);
// 	result2 = ft_strcmp(c1, c2);
// 	passed = result1 == result2;
// 	printf("s1: %s s2: %s strcmp: %d ft_strcmp: %d passed: %d\n", c1, c1,
// 			result1, result2, passed);
// 	if (!passed)
// 		exit(-1);
// }

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	for (int i = -100; i < 100; i++)
// 	{
// 		s1 = random_string(random_in_range(20));
// 		s2 = random_string(random_in_range(20));
// 		test_strings(s1, s2);
// 	}
// 	test_strings("abcdef", "abcdefg");
// 	test_strings("abcdefg", "abcdef");
// 	test_strings("", "");
// 	return (0);
// }
