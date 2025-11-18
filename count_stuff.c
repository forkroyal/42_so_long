/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:38 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 14:18:10 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_of(char **map, char what_to_find);

int	count_of(char **map, char what_to_find)
{
	int	c_count;
	int	i;
	int	j;

	c_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == what_to_find)
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}
