/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:27 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 14:17:32 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_c(char **s)
{
	int	c_count;
	int	i;
	int	j;

	c_count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'c')
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

// int main()
// {
// 	char *hello[] = {"hello", "cousin", NULL};

// 	//printf("%c\n", hello[0][2]);
// 	printf("%i\n", check_c(hello));
// }
