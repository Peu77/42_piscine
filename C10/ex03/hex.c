/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:25:37 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:23:24 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <unistd.h>

int	file_size_of(char *filename)
{
	int		fd;
	int		size;
	char	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 0;
	while (read(fd, buf, 1) > 0)
		size++;
	close(fd);
	return (size);
}

void	print_hex_content(char *buf, int size, int split_in_half)
{
	int	i;

	if (split_in_half)
		ft_putchar(' ');
	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex(buf[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (split_in_half && i == 7)
			ft_putchar(' ');
		if (i++ != 15)
			ft_putchar(' ');
	}
	if (split_in_half)
		ft_putchar(' ');
}

int	hex_dump(int fd, int is_last)
{
	char	buf[16];
	int		read_bytes;
	int		i;
	int		prev_read_bytes;

	i = 0;
	while (1)
	{
		read_bytes = read(fd, buf, 16);
		if (read_bytes <= 0)
			break ;
		prev_read_bytes = read_bytes;
		print_addr(i, 7);
		ft_putchar(' ');
		print_hex_content(buf, read_bytes, 0);
		ft_putchar('\n');
		i += 16;
	}
	if (i != 0 && is_last)
	{
		i = i - 16 + prev_read_bytes;
		print_addr(i, 7);
		ft_putchar('\n');
	}
	return (close(fd), 1);
}

void	hex_dump_c_flag_loop(char *buf, int read_bytes, int *i)
{
	int	j;

	print_addr(*i, 8);
	ft_putchar(' ');
	print_hex_content(buf, read_bytes, 1);
	ft_putchar(' ');
	write(1, "|", 1);
	j = 0;
	while (j < read_bytes)
	{
		if (buf[j] < 32 || buf[j] > 126)
			ft_putchar('.');
		else
			ft_putchar(buf[j]);
		j++;
	}
	write(1, "|", 1);
	ft_putchar('\n');
	*i += 16;
}

int	hex_dump_c_flag(int fd, int is_last)
{
	char	buf[16];
	int		read_bytes;
	int		prev_read_bytes;
	int		i;

	i = 0;
	while (1)
	{
		read_bytes = read(fd, buf, 16);
		if (read_bytes == 0)
			break ;
		prev_read_bytes = read_bytes;
		hex_dump_c_flag_loop(buf, read_bytes, &i);
	}
	if (i != 0 && is_last)
	{
		i -= 16;
		i += prev_read_bytes;
		print_addr(i, 8);
		ft_putchar('\n');
	}
	close(fd);
	return (1);
}
