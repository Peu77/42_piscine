/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:53 by eebert            #+#    #+#             */
/*   Updated: 2024/08/20 20:05:25 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void	ft_putstr(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	read_file(const char *filename)
{
	const int	fp = open(filename, 0);
	char		buffer[BUFFER_SIZE];
	int			read_bytes;

	if (fp == -1)
		return (0);
	while (1)
	{
		read_bytes = read(fp, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		if (read_bytes <= 0)
			break ;
		write(1, buffer, read_bytes);
	}
	close(fp);
	return (1);
}

int	main(int argc, char **args)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}
	if (!read_file(args[1]))
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	return (0);
}
