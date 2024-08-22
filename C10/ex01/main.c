/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:53 by eebert            #+#    #+#             */
/*   Updated: 2024/08/20 22:02:18 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 30000

void	ft_putstr(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	read_fd(int fd, char *filename)
{
	char	buffer[BUFFER_SIZE];
	int		read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return ;
		if (read_bytes <= 0)
			break ;
		if (errno != 0 && fd == 0)
		{
			ft_putstr(basename(filename), 2);
			ft_putstr(": stdin: ", 2);
			ft_putstr(strerror(errno), 2);
			ft_putstr("\n", 2);
			return ;
		}
		write(1, buffer, read_bytes);
	}
	if (fd != 0)
		close(fd);
}

void	parse_arguments(int argc, char **args)
{
	int	i;
	int	fp;

	i = 1;
	while (i < argc)
	{
		if (args[i][0] == '-')
			read_fd(0, args[0]);
		else
		{
			fp = open(args[i], 0);
			if (fp >= 0)
				read_fd(fp, args[0]);
			else
			{
				ft_putstr(basename(args[0]), 2);
				ft_putstr(": ", 2);
				ft_putstr(args[i], 2);
				ft_putstr(": ", 2);
				ft_putstr(strerror(errno), 2);
				ft_putstr("\n", 2);
			}
		}
		i++;
	}
}

int	main(const int argc, char **argv)
{
	if (argc == 1)
	{
		read_fd(0, argv[0]);
		return (0);
	}
	parse_arguments(argc, argv);
	return (0);
}
