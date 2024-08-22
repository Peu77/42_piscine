/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:40:24 by eebert            #+#    #+#             */
/*   Updated: 2024/08/12 13:18:54 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

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

char	*allocate_string(int length)
{
	char	*str;
	int		i;

	str = (char *)malloc((length + 1) * sizeof(char));
	i = 0;
	while (i <= length)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	char_size_of_string_array(char **strs, int len, int sep_len)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < len)
	{
		size += ft_str_len(strs[i]);
		if (i != len - 1)
			size += sep_len;
		i++;
	}
	return (size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		dest_len;
	int		sep_len;

	if (size <= 0)
	{
		dest = (char *)malloc(sizeof(char));
		*dest = 0;
		return (dest);
	}
	sep_len = ft_str_len(sep);
	dest_len = char_size_of_string_array(strs, size, sep_len);
	i = 0;
	dest = allocate_string(dest_len);
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != size - 1 && sep_len > 0)
			ft_strcat(dest, sep);
		i++;
	}
	dest[dest_len] = 0;
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs[] = {"Hello", "world!", "fewfew"};

// 	printf("%s", ft_strjoin(3, strs, "  "));
// }
