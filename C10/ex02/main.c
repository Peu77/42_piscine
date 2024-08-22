/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:48:49 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 15:55:14 by eebert           ###   ########.fr       */
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

char	*get_tail_of_file(const char *filename, int tail_bytes, int file_size)
{
	const int	fp = open(filename, O_RDONLY);
	char		*buffer;

	if (fp == -1)
		return (0);
	if (tail_bytes > file_size)
		tail_bytes = file_size;
	buffer = malloc(tail_bytes + 1);
	buffer[tail_bytes] = 0;
	if (buffer == 0)
		return (0);
	tail_n_bytes(fp, tail_bytes, file_size, buffer);
	close(fp);
	return (buffer);
}

void	output_wrong_offset_error(char *offset, char *filename)
{
	write(2, basename(filename), ft_strlen(basename(filename)));
	write(2, ": ", 2);
	write(2, "illegal offset -- ", 18);
	write(2, offset, ft_strlen(offset));
	write(2, "\n", 1);
}

int	parse_arguments(int argc, char **argv, int *i_offset)
{
	int	arg_c_len;

	*i_offset = 0;
	arg_c_len = ft_strlen(argv[1]);
	if (arg_c_len > 2)
	{
		if (!is_number(argv[1] + 2))
			return (output_wrong_offset_error(argv[1] + 2, argv[0]), -1);
		*i_offset = 2;
		return (ft_atoi(argv[1] + 2));
	}
	if (argc == 2)
		return (print_help(argv[0]), -1);
	if (!is_number(argv[2]))
		return (output_wrong_offset_error(argv[2], argv[0]), -1);
	*i_offset = 3;
	return (ft_atoi(argv[2]));
}

void	print_files(int argc, char **argv, int i, int bytes)
{
	int			file_size;
	char		*tail;
	const int	print_names = argc - i > 1;

	while (i < argc)
	{
		file_size = get_file_size(argv[i]);
		if (file_size == -1)
		{
			write(2, basename(argv[0]), ft_strlen(argv[0]));
			write(2, ": ", 2);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, ": ", 2);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			i++;
			continue ;
		}
		if (print_names)
			print_file_name(argv[i]);
		tail = get_tail_of_file(argv[i], bytes, file_size);
		write(1, tail, bytes);
		free(tail);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	bytes;
	int	i;

	if (argc == 1)
	{
		no_argument(argv[0]);
		return (0);
	}
	bytes = parse_arguments(argc, argv, &i);
	if (bytes == -1)
		return (1);
	if (i == argc)
		tail_stdin(bytes);
	else
		print_files(argc, argv, i, bytes);
	return (0);
}
