/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:04:44 by eebert            #+#    #+#             */
/*   Updated: 2024/08/05 13:41:43 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	char			c1;
	char			c2;

	i = 0;
	while (i < n)
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

// void	test_strings(char *c1, char *c2, unsigned int n)
// {
// 	int	passed;
// 	int	result1;
// 	int	result2;

// 	result1 = strncmp(c1, c2, n);
// 	result2 = ft_strncmp(c1, c2, n);
// 	passed = result1 == result2;
// 	printf("s1: %s s2: %s strcmp: %d ft_strcmp: %d passed: %d\n", c1, c2,
// 		result1, result2, passed);
// 	if (!passed)
// 		exit(-1);
// }

// int	main(void)
// {
// 	char			*s1;
// 	char			*s2;
// 	unsigned int	n;

// 	for (int i = -100; i < 100; i++)
// 	{
// 		n = random_in_range(20);
// 		s1 = random_string(random_in_range(20));
// 		s2 = random_string(random_in_range(20));
// 		test_strings(s1, s2, n);
// 	}
// 	test_strings("abcdef", "abcdefg", 7);
// 	test_strings("abcdefg", "abcdef", 6);
// 	test_strings("abcdefg", "abcdef", 3);
// 	return (0);
// }
