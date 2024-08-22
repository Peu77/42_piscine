/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:32:41 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:28:54 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

int		hex_dump_c_flag(int fd, int is_last);

int		hex_dump(int fd, int is_last);

int		file_size_of(char *filename);

void	print_error(char *filename, char *target)
{
	ft_putstr(basename(filename));
	ft_putstr(": ");
	ft_putstr(target);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	ft_putstr(basename(filename));
	ft_putstr(": ");
	ft_putstr(target);
	ft_putstr(": ");
	ft_putstr("Bad file descriptor");
	ft_putstr("\n");
	errno = 0;
}

int	has_c_flag(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	return (argv[1][0] == '-' && argv[1][1] == 'C');
}

int	last_openable(char **argv, int argc, int i)
{
	int	fd;

	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (i - 1);
		close(fd);
		i++;
	}
	return (argc - 1);
}

void	print_hex_dump(char **argv, int i, int last_openable_index,
		int (*f)(int, int))
{
	int	fd;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		print_error(argv[0], argv[i]);
		i++;
		return ;
	}
	f(fd, i == last_openable_index);
}

int	main(int argc, char **argv)
{
	int	i;
	int	(*f)(int, int);
	int	last_openable_index;

	i = 1;
	if (has_c_flag(argc, argv))
	{
		i++;
		f = &hex_dump_c_flag;
	}
	else
		f = &hex_dump;
	if ((argc == 2 && has_c_flag(argc, argv)) || argc == 1)
		return (f(0, 1), 1);
	last_openable_index = last_openable(argv, argc, i);
	while (i < argc)
	{
		print_hex_dump(argv, i, last_openable_index, f);
		i++;
	}
	return (1);
}
