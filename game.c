/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:32:49 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/25 17:03:40 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		start_game(t_mapdata *mapdata, t_windata *win);
void	del_dest_cl(t_windata *win, int code);
void	my_xpm_to_img(t_windata *win);
void	fillwindow(t_windata *win);

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
	my_xpm_to_img(win);
	win->win_ptr = mlx_new_window(win->mlx_ptr, mapdata->map_width_x * PIXEL,
			mapdata->map_height_y * PIXEL, "so_long");
	if (!win->win_ptr)
	{
		del_dest_cl(win, 1);
		return (FALSE);
	}
	fillwindow(win);
	// hook function
	// if loop > return
	// del_dest_cl
	// return
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

void	my_xpm_to_img(t_windata *win)
{
	win->img[0].img = mlx_xpm_file_to_image(win->mlx_ptr, "./pixmaps/BG.xpm",
			&win->img->img_w_x, &win->img->img_h_y);
	win->img[1].img = mlx_xpm_file_to_image(win->mlx_ptr, "./pixmaps/W.xpm",
			&win->img->img_w_x, &win->img->img_h_y);
	win->img[2].img = mlx_xpm_file_to_image(win->mlx_ptr, "./pixmaps/P.xpm",
			&win->img->img_w_x, &win->img->img_h_y);
	win->img[3].img = mlx_xpm_file_to_image(win->mlx_ptr, "NV./pixmaps/.xpm",
			&win->img->img_w_x, &win->img->img_h_y);
	win->img[4].img = mlx_xpm_file_to_image(win->mlx_ptr, "./pixmaps/E.xpm",
			&win->img->img_w_x, &win->img->img_h_y);
	if (!win->img[0].img || !win->img[1].img || !win->img[2].img
		|| !win->img[3].img || !win->img[4].img)
	{
		ft_printf("Error: in creating images!\n");
		del_dest_cl(win, 1);
		return ;
	}
}

void	fillwindow(t_windata *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->mapdata->map[i])
	{
		j = 0;
		while (win->mapdata->map[i][j])
		{
			if (win->mapdata->map[i][j] == BG)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img[0].img, j * PIXEL, i * PIXEL);
			else if (win->mapdata->map[i][j] == BORDER)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img[1].img, j * PIXEL, i * PIXEL);
			else if (win->mapdata->map[i][j] == PLAYER)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img[2].img, j * PIXEL, i * PIXEL);
			else if (win->mapdata->map[i][j] == COIN)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img[3].img, j * PIXEL, i * PIXEL);	
			else if (win->mapdata->map[i][j] == EXIT)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img[4].img, j * PIXEL, i * PIXEL);
			j++;
		}
		i++;
	}
}
