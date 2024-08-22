/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:03:51 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:31:12 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "tail.h"
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	tail_n_bytes(int fd, int n, int file_size, char *buffer)
{
	int		bytes_read;
	int		last_bytes;
	int		i;
	char	buffer2[BUFFER_SIZE];

	bytes_read = 0;
	i = 0;
	while (1)
	{
		if (BUFFER_SIZE + bytes_read > file_size - n)
		{
			read(fd, buffer2, file_size - n - bytes_read);
			break ;
		}
		last_bytes = read(fd, buffer2, BUFFER_SIZE);
		if (last_bytes == -1)
			return ;
		if (last_bytes <= 0)
			break ;
		bytes_read += last_bytes;
	}
	read(fd, buffer, n);
}

int	get_file_size(const char *filename)
{
	const int	fp = (open(filename, O_RDONLY));
	char		buffer[BUFFER_SIZE];
	int			bytes_read;
	int			last_bytes;
	int			i;

	if (fp == -1)
		return (-1);
	bytes_read = 0;
	i = 0;
	while (1)
	{
		last_bytes = read(fp, buffer, BUFFER_SIZE);
		if (last_bytes == -1)
		{
			return (0);
		}
		if (last_bytes <= 0)
			break ;
		bytes_read += last_bytes;
	}
	close(fp);
	return (bytes_read);
}

void	shift_buffer(char *buffer, int n)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		buffer[i - 1] = buffer[i];
	}
}

void	tail_stdin(int n)
{
	char	*buffer;
	int		i;
	char	tmp[1];

	buffer = malloc(n + 1);
	if (buffer == 0)
		return ;
	buffer[n] = 0;
	i = 0;
	while (read(0, tmp, 1) > 0)
	{
		if (i < n)
		{
			buffer[i] = tmp[0];
			i++;
		}
		else
		{
			shift_buffer(buffer, n);
			buffer[n - 1] = tmp[0];
		}
	}
	write(1, buffer, n);
	free(buffer);
}

void	no_argument(char *filename)
{
	char	buffer[1];

	while (read(0, buffer, 1) > 0)
	{
		if (errno != 0)
		{
			write(2, basename(filename), ft_strlen(basename(filename)));
			write(2, ": stdin: ", 9);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
		}
	}
}
