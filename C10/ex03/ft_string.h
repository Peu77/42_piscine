/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:51:44 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:24:00 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_hex(unsigned char c);
void	print_addr(int i, int len);

#endif