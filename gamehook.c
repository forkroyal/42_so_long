/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamehook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:37:13 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/26 01:02:08 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_hook(t_windata win);
int	kill_all(t_windata *win);
int	key(int keysym, t_windata *win);

int	kill_all(t_windata *win)
{
	del_dest_cl(win, 0);
	return (0);
}
int	key(int keysym, t_windata *win)
{
	if (keysym == ESC)
	{
		kill_all(win);
		return (0);
	}
	fillwindow(win);
	// end_game(win);
	return (0);
}

int	my_hook(t_windata win)
{
	mlx_hook(win.win_ptr, 2, 1, key, &win);
	mlx_hook(win.win_ptr, 17, 17, kill_all, &win);
	return (0);
}
