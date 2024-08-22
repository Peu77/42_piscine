/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:46:44 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 13:05:05 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar('c');
// }

/*
files=$(find . -type f -name "*.c")

mkdir temp bin

for file in $files;
do
	base_name=$(basename "$file" .c);
	new_file="temp/$base_name.c"

	sed 's|//||g' $file > $new_file
	cc  -Wall -Wextra -Werror $new_file -o "bin/$base_name"
done

count=$(find bin -type f| wc -l | tr -d " ")
echo "bin count: $count"
*/