/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:22:57 by fausto            #+#    #+#             */
/*   Updated: 2022/11/30 05:41:13 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_color(t_data *data, int w, int ty_init, float ty)
{
	int	c;

	c = 0;
	if (data->ray[w].hited_wall == 'x')
	{
		if (data->ray[w].angle > 0 && data->ray[w].angle < PI)
			c = data->txtr.no.addr[(ty_init + ((int)ty * 64))];
		else if (data->ray[w].angle > PI && data->ray[w].angle < 2 * PI)
			c = data->txtr.so.addr[(ty_init + ((int)ty * 64))];
	}
	else if (data->ray[w].hited_wall == 'y')
	{
		if (data->ray[w].angle > PI / 2
			&& data->ray[w].angle < 3 * ((2 * PI) / 4))
			c = data->txtr.we.addr[(ty_init + ((int)ty * 64))];
		else if (data->ray[w].angle > 3 * ((2 * PI) / 4)
			|| data->ray[w].angle < PI / 2)
			c = data->txtr.ea.addr[(ty_init + ((int)ty * 64))];
	}
	return (c);
}

static void	define_wall_height(t_data *data, int w)
{
	if (data->ray[w].ray_size != 0)
	{
		data->ray[w].wall_height = ((MAPCELL * (data->game->win_height)))
			/ data->ray[w].ray_size;
	}
	else
		data->ray[w].wall_height = ((MAPCELL * (data->game->win_height))) / 1;
	data->ray[w].ty_step = ((float)64 / (float)data->ray[w].wall_height);
	data->ray[w].ty_offset = 0;
	if (data->ray[w].wall_height > data->game->win_height)
	{
		data->ray[w].ty_offset = (data->ray[w].wall_height
				- data->game->win_height) / 2;
		data->ray[w].wall_height = data->game->win_height;
	}
}

void	ray_casting_wall(t_data *data)
{
	int		i;
	int		j;
	int		w;

	j = (data->game->win_width);
	w = 0;
	while (--j >= 0)
	{
		define_wall_height(data, w);
		i = -1;
		data->pix_y_pos = (((data->game->win_height)) / 2)
			- (data->ray[w].wall_height / 2);
		print_celing(data, &i, j);
		data->pix_y_pos = i + data->ray[w].wall_height;
		print_wall(data, &i, j, w);
		--i;
		print_floor(data, &i, j);
		w++;
	}
}
