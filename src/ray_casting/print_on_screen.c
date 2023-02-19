/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:29:58 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:16 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_celing(t_data *data, int *i, int j)
{
	char	*dst;

	while (++(*i) < data->pix_y_pos)
	{
		dst = data->game->addr + (unsigned int)(*i) *data->game->line_length
			+ ((unsigned int)j * (data->game->bits_per_pixel / 8));
		*(unsigned int *)dst = data->map->c[3];
	}
}

void	print_wall(t_data *data, int *i, int j, int w)
{
	char	*dst;
	int		c;

	if (data->ray[w].hited_wall == 'x')
		data->ray[w].ty_init = data->ray[w].cell_y_pos;
	else if (data->ray[w].hited_wall == 'y')
		data->ray[w].ty_init = data->ray[w].cell_x_pos;
	data->ray[w].ty = data->ray[w].ty_offset * data->ray[w].ty_step;
	while (++(*i) < data->pix_y_pos)
	{
		c = calc_color(data, w, data->ray[w].ty_init, data->ray[w].ty);
		dst = data->game->addr + (unsigned int)(*i) *data->game->line_length
			+ ((unsigned int)j * (data->game->bits_per_pixel / 8));
		*(unsigned int *)dst = c;
		data->ray[w].ty += data->ray[w].ty_step;
	}
}

void	print_floor(t_data *data, int *i, int j)
{
	char	*dst;

	while (++(*i) < data->game->win_height)
	{
		dst = data->game->addr + (unsigned int)(*i) *data->game->line_length
			+ ((unsigned int)j * (data->game->bits_per_pixel / 8));
		*(unsigned int *)dst = data->map->f[3];
	}
}
