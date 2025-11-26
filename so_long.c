/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:38:11 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/26 01:53:47 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mapdata	mapdata;
	t_windata	windata;

	if (!check_input(argc, argv[1]))
		return (FALSE);
	if (!fill_mapdata(&mapdata, argv[1]))
		return (FALSE);
	if (!check_path(&mapdata, argv[1]))
		return (FALSE);
	if (!start_game(&mapdata, &windata))
		return (FALSE);
}

// += t_data data; // for window zeile 18
