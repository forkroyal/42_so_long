/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:32:49 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/22 14:35:33 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		start_game(t_mapdata *mapdata, t_windata *win);
void	del_dest_cl(t_windata *win, int code);

int	start_game(t_mapdata *mapdata, t_windata *win)
{
	t_imagedata	img[5];

	win->mapdata = mapdata;
	win->img = img;
	win->win_ptr = NULL;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		del_dest_cl(win, 1);
		return (FALSE);
	}
	
	del_dest_cl(win, 0);
	return (0);
}

void	del_dest_cl(t_windata *win, int code)
{
	int	i;

	i = 0;
	free_map(win->mapdata->map);
	while (i < IMAGES)
	{
		if (win->img[i].img && win->mlx_ptr)
		{
			mlx_destroy_image(win->mlx_ptr, win->img[i].img);
			win->img[i].img = NULL;
		}
		i++;
	}
	if (win->win_ptr)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		win->win_ptr = NULL;
	}
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		win->mlx_ptr = NULL;
	}
	exit(code);
}
