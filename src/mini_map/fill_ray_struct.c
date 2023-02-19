/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:45:00 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/09/06 20:09:06 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hit_y_angle_minor_pi(t_data *data, t_ray *ray);
static void	hit_y_angle_major_pi(t_data *data, t_ray *ray);
static void	hit_x_angle_minor_pi(t_data *data, t_ray *ray);
static void	hit_x_angle_major_pi(t_data *data, t_ray *ray);

void	fill_ray_struct(t_data *data, t_ray *ray, int size)
{
	if (ray->hited_wall == 'y')
	{
		if (ray->angle < PI)
			hit_y_angle_minor_pi(data, ray);
		else
			hit_y_angle_major_pi(data, ray);
	}
	else if (ray->hited_wall == 'x')
	{
		if (ray->angle < PI)
			hit_x_angle_minor_pi(data, ray);
		else
			hit_x_angle_major_pi(data, ray);
	}
}

static void	hit_y_angle_minor_pi(t_data *data, t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < PI / 2)
	{
		ray->map_x_pos = data->player->x - ray->delta_x;
		ray->map_y_pos = data->player->y + ray->delta_y;
		ray->cell_x_pos = (int)ray->map_x_pos % MAPCELL;
		ray->cell_y_pos = 0;
	}
	else if (ray->angle > PI / 2 && ray->angle < PI)
	{
		ray->map_x_pos = data->player->x - ray->delta_x;
		ray->map_y_pos = data->player->y - ray->delta_y;
		ray->cell_x_pos = (int)ray->map_x_pos % MAPCELL;
		ray->cell_y_pos = 0;
	}
}

static void	hit_y_angle_major_pi(t_data *data, t_ray *ray)
{
	if (ray->angle > PI && ray->angle < 3 * ((2 * PI) / 4))
	{
		ray->map_x_pos = data->player->x + ray->delta_x;
		ray->map_y_pos = data->player->y - ray->delta_y;
		ray->cell_x_pos = (int)ray->map_x_pos % MAPCELL;
		ray->cell_y_pos = 0;
	}
	else if (ray->angle > 3 * ((2 * PI) / 4) && ray->angle < 2 * PI)
	{
		ray->map_x_pos = data->player->x + ray->delta_x;
		ray->map_y_pos = data->player->y + ray->delta_y;
		ray->cell_x_pos = (int)ray->map_x_pos % MAPCELL;
		ray->cell_y_pos = 0;
	}
}

static void	hit_x_angle_minor_pi(t_data *data, t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < PI / 2)
	{
		ray->map_y_pos = data->player->y + ray->delta_y;
		ray->map_x_pos = data->player->x - ray->delta_x;
		ray->cell_y_pos = (int)ray->map_y_pos % MAPCELL;
		ray->cell_x_pos = 0;
	}
	else if (ray->angle > PI / 2 && ray->angle < PI)
	{
		ray->map_y_pos = data->player->y - ray->delta_y;
		ray->map_x_pos = data->player->x - ray->delta_x;
		ray->cell_y_pos = (int)ray->map_y_pos % MAPCELL;
		ray->cell_x_pos = 0;
	}
}

static void	hit_x_angle_major_pi(t_data *data, t_ray *ray)
{
	if (ray->angle > PI && ray->angle < 3 * ((2 * PI) / 4))
	{
		ray->map_y_pos = data->player->y - ray->delta_y;
		ray->map_x_pos = data->player->x + ray->delta_x;
		ray->cell_y_pos = ((int)ray->map_y_pos % MAPCELL);
		ray->cell_x_pos = 0;
	}
	else if (ray->angle > 3 * ((2 * PI) / 4) && ray->angle < 2 * PI)
	{
		ray->map_y_pos = data->player->y + ray->delta_y;
		ray->map_x_pos = data->player->x + ray->delta_x;
		ray->cell_y_pos = (int)ray->map_y_pos % MAPCELL;
		ray->cell_x_pos = 0;
	}
}
