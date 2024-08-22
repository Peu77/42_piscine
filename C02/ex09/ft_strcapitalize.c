/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:28 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 10:48:38 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_charupcase(char *c_pointer)
{
	char	c;

	c = *c_pointer;
	if (c >= 'a' && c <= 'z')
	{
		*c_pointer -= 32;
	}
}

void	ft_charlowcase(char *c_pointer)
{
	*c_pointer += 32;
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		in_word;
	char	c;
	int		is_alpha;

	is_alpha = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		c = str[i];
		is_alpha = ft_char_is_alpha(c);
		if (!in_word && is_alpha)
		{
			ft_charupcase(&str[i]);
			in_word = 1;
			i++;
			continue ;
		}
		in_word = is_alpha || (c >= '0' && c <= '9');
		if (in_word && c <= 'Z' && c >= 'A')
			ft_charlowcase(&str[i]);
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "salut,
//			comment tu vas ? 42mots quarante-deux; cinquante+et+un";

// 	printf("before: %s\n", str);
// 	ft_strcapitalize(str);
// 	printf("after: %s\n", str);
// 	return (0);
// }
