/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:55:25 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 14:36:00 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 4;
// 	ft_ft(&i);
// 	printf("i: %d", i);
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