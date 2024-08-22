/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:02:13 by eebert            #+#    #+#             */
/*   Updated: 2024/08/20 17:54:59 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		is_number(char *str);
void	print_file_name(char *file_name);

#endif