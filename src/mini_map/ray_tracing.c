/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:32:19 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/11/29 15:19:09 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mini_map_ray(t_data *data, t_player **player, t_ray *ray, int z);
static char	chose_minor_ray(t_ray *ray, int h, int v);

void	ray_tracing(t_data *data, t_ray *ray, int i)
{
	double		delta_angle;
	t_player	*plyr;
	t_game		*game;

	plyr = data->player;
	game = data->game;
	ray->degree = ((PI * 60) / 180) / (double)(data->game->win_width);
	ray->angle = (plyr->angle - (double)((PI * 30) / 180)) + (i * ray->degree);
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
	else if (ray->angle < 0)
		ray->angle += 2 * PI;
	delta_angle = - (double)((PI * 30) / 180) + (i * ray->degree);
	ray->ray_size = mini_map_ray(data, &data->player, ray, i);
	if (delta_angle < 0)
		ray->ray_size *= cos(-1 * delta_angle);
	else
		ray->ray_size *= cos(delta_angle);
}

static int	mini_map_ray(t_data *data, t_player **player, t_ray *ray, int z)
{
	int		size;
	int		v;
	int		h;

	h = ray_x(data->map, player, ray);
	v = ray_y(data, player, ray);
	if (chose_minor_ray(ray, h, v) == 'x')
		size = ray_x(data->map, player, ray);
	else if (chose_minor_ray(ray, h, v) == 'y')
		size = v;
	else
		size = 0;
	fill_ray_struct(data, ray, size);
	return (size);
}

static char	chose_minor_ray(t_ray *ray, int h, int v)
{
	if (h < v)
	{
		if (h < 0)
			return (ray->hited_wall = 'y');
		else
			return (ray->hited_wall = 'x');
	}
	else
	{
		if (v < 0)
			return (ray->hited_wall = 'x');
		else
			return (ray->hited_wall = 'y');
	}
}	
