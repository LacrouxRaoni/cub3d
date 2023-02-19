/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:36:02 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:57 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_foward_backward(int key, t_player **player, char **map)
{
	int	x;
	int	y;

	if (key == KEY_W)
	{	
		x = ((*player)->x - sin((*player)->angle) * (WALK_STEP + 50)) / MAPCELL;
		y = ((*player)->y + cos((*player)->angle) * (WALK_STEP + 50)) / MAPCELL;
		if (map[x][y] != '1')
		{
			(*player)->x -= sin((*player)->angle) * WALK_STEP;
			(*player)->y += cos((*player)->angle) * WALK_STEP;
		}
	}
	else if (key == KEY_S)
	{
		x = ((*player)->x + sin((*player)->angle) * (WALK_STEP + 50)) / MAPCELL;
		y = ((*player)->y - cos((*player)->angle) * (WALK_STEP + 50)) / MAPCELL;
		if (map[x][y] != '1')
		{
			(*player)->x += sin((*player)->angle) * WALK_STEP;
			(*player)->y -= cos((*player)->angle) * WALK_STEP;
		}
	}
}

void	move_left(int key, t_player **player, char **map)
{
	int	x;
	int	y;

	if (key == KEY_A)
	{
		x = ((*player)->x + sin((*player)->angle
					- (PI / 2)) * (WALK_STEP + 50)) / MAPCELL;
		y = ((*player)->y - cos((*player)->angle
					- (PI / 2)) * (WALK_STEP + 50)) / MAPCELL;
		if (map[x][y] != '1')
		{
			(*player)->x += sin((*player)->angle - (PI / 2)) * WALK_STEP;
			(*player)->y -= cos((*player)->angle - (PI / 2)) * WALK_STEP;
		}
	}
}

void	move_right(int key, t_player **player, char **map)
{
	int	x;
	int	y;

	if (key == KEY_D)
	{
		x = ((*player)->x + sin((*player)->angle
					+ (PI / 2)) * (WALK_STEP + 50)) / MAPCELL;
		y = ((*player)->y - cos((*player)->angle
					+ (PI / 2)) * (WALK_STEP + 50)) / MAPCELL;
		if (map[x][y] != '1')
		{
			(*player)->x += sin((*player)->angle + (PI / 2)) * WALK_STEP;
			(*player)->y -= cos((*player)->angle + (PI / 2)) * WALK_STEP;
		}
	}
}

void	turn_left_right(int key, t_data *data)
{
	if (key == KEY_LEFT)
	{
		data->player->angle += 0.1;
		while (data->player->angle > 2 * PI)
			data->player->angle -= 2 * PI;
	}
	else if (key == KEY_RIGHT)
	{
		data->player->angle -= 0.1;
		while (data->player->angle < 0)
			data->player->angle += 2 * PI;
	}
}
