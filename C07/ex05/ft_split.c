/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:51:19 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 18:13:01 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			count++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*allocate_word(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words;
	int		i;

	words = count_words(str, charset);
	i = 0;
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			result[i] = allocate_word(str, charset);
			if (!result[i])
				return (0);
			i++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	result[i] = 0;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **result;
// 	char *str = " Hello,  world! This is a test string.     ";
// 	char *charset = " ,!";

// 	result = ft_split(str, charset);
// 	if (!result)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	for (int i = 0; result[i]; i++)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 	}
// 	free(result);
// 	return (0);
// }