/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:07:24 by fausto            #+#    #+#             */
/*   Updated: 2022/09/07 12:38:28 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	int	x;
	int	y;

	if (key == KEY_ESC)
		clean(data);
	move_foward_backward(key, &data->player, data->map->map);
	move_left(key, &data->player, data->map->map);
	move_right(key, &data->player, data->map->map);
	turn_left_right(key, data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
	{
		data->player->x -= 0;
		data->player->y += 0;
	}
	else if (key == KEY_S)
	{
		data->player->x += 0;
		data->player->y -= 0;
	}
	if (key == KEY_A)
	{
		data->player->x += 0;
		data->player->y -= 0;
	}
	if (key == KEY_D)
	{
			data->player->x += 0;
			data->player->y -= 0;
	}
	if (key == KEY_LEFT)
		data->player->angle += 0;
	else if (key == KEY_RIGHT)
		data->player->angle -= 0;
}
