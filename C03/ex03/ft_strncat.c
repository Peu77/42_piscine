/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:30:00 by eebert            #+#    #+#             */
/*   Updated: 2024/08/05 17:30:01 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	write_index;
	unsigned int	read_index;

	write_index = 0;
	read_index = 0;
	while (dest[write_index])
		write_index++;
	while (src[read_index] && read_index < nb)
	{
		dest[write_index] = src[read_index];
		write_index++;
		read_index++;
	}
	dest[write_index] = 0;
	return (dest);
}
