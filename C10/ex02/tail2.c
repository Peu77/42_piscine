/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:31:22 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:31:46 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "tail.h"
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <unistd.h>

void	print_help(char *filename)
{
	write(2, basename(filename), ft_strlen(basename(filename)));
	write(2, ": option require an argument -- c\nusage: ", 42);
	write(2, basename(filename), ft_strlen(basename(filename)));
	write(2, " [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 55);
}
