/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:04:27 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 15:51:17 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# define BUFFER_SIZE 30000

void	tail_n_bytes(int fd, int n, int file_size, char *buffer);
int		get_file_size(const char *filename);
void	tail_stdin(int n);
void	no_argument(char *filename);
void	print_help(char *filename);

#endif