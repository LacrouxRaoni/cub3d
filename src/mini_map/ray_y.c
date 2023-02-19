/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:47:45 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/09/01 12:16:35 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ray_y_ne(t_data *data, t_player **player, t_ray *ray, double angle);
static int	ray_y_nw(t_data *data, t_player **player, t_ray *ray, double angle);
static int	ray_y_se(t_data *data, t_player **player, t_ray *ray, double angle);
static int	ray_y_sw(t_data *data, t_player **player, t_ray *ray, double angle);

int	ray_y(t_data *data, t_player **player, t_ray *ray)
{
	int		i;

	i = -1;
	if (ray->angle > 0 && ray->angle <= PI / 2)
		i = ray_y_ne(data, player, ray, ray->angle);
	else if (ray->angle > (PI / 2) && ray->angle <= PI)
		i = ray_y_nw(data, player, ray, ray->angle);
	else if (ray->angle > PI && ray->angle < 3 * (2 * PI / 4))
		i = ray_y_sw(data, player, ray, ray->angle);
	else if (ray->angle > 3 * (2 * PI / 4) && ray->angle <= 2 * PI)
		i = ray_y_se(data, player, ray, ray->angle);
	else if (ray->angle == 3 * (2 * PI / 4) && ray->angle == PI / 2)
		return (-1);
	return (i);
}

static int	ray_y_ne(t_data *data, t_player **player, t_ray *ray, double angle)
{
	int	i;

	i = -1;
	ray->delta_y = MAPCELL - ((int)(*player)->y % MAPCELL);
	ray->delta_x = ray->delta_y * tan(angle);
	if ((int)(*player)->x - ray->delta_x > 0 && (int)(*player)->x
			- ray->delta_x < data->map->max_height * MAPCELL)
	{
		ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		while (data->map->map[ray->cell_x][ray->cell_y] != '1'
			&& data->map->map[ray->cell_x][ray->cell_y] != ' ')
		{
			ray->delta_y += MAPCELL;
			ray->delta_x = ray->delta_y * tan(angle);
			if ((int)(*player)->x - ray->delta_x < 0 || (int)(*player)->x -
				ray->delta_x > data->map->max_height * MAPCELL)
				return (-1);
			ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
			i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		}
	}
	return (i);
}

static int	ray_y_nw(t_data *data, t_player **player, t_ray *ray, double angle)
{
	int		i;

	i = -1;
	ray->delta_y = (int)(*player)->y % MAPCELL;
	ray->delta_x = ray->delta_y * (-tan (angle));
	if ((int)(*player)->x - ray->delta_x > 0 && (int)(*player)->x
	- ray->delta_x < data->map->max_height * MAPCELL)
	{
		ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		i = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		while (data->map->map[ray->cell_x][ray->cell_y - 1] != '1'
			&& data->map->map[ray->cell_x][ray->cell_y - 1] != ' ')
		{
			ray->delta_y += MAPCELL;
			ray->delta_x = ray->delta_y * (-tan (angle));
			if ((int)(*player)->x - ray->delta_x < 0 || (int)(*player)->x
						- ray->delta_x > data->map->max_height * MAPCELL)
				return (-1);
			ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
			i = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		}
	}
	return (i);
}

static int	ray_y_sw(t_data *data, t_player **player, t_ray *ray, double angle)
{
	int	i;

	i = -1;
	ray->delta_y = (int)(*player)->y % MAPCELL;
	ray->delta_x = ray->delta_y * tan(angle);
	if ((int)(*player)->x + ray->delta_x > 0 && (int)(*player)->x
			+ ray->delta_x < data->map->max_height * MAPCELL)
	{
		ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		while (data->map->map[ray->cell_x][ray->cell_y - 1] != '1'
			&& data->map->map[ray->cell_x][ray->cell_y - 1] != ' ')
		{
			ray->delta_y += MAPCELL;
			ray->delta_x = ray->delta_y * tan(angle);
			if ((int)(*player)->x + ray->delta_x < 0 || (int)(*player)->x
				+ ray->delta_x > data->map->max_height * MAPCELL)
				return (-1);
			ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
			i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		}
	}
	return (i);
}

static int	ray_y_se(t_data *data, t_player **player, t_ray *ray, double angle)
{
	int	i;

	i = -1;
	ray->delta_y = MAPCELL - ((int)(*player)->y % MAPCELL);
	ray->delta_x = ray->delta_y * (-tan (angle));
	if ((int)(*player)->x + ray->delta_x > 0 && (int)(*player)->x
		+ ray->delta_x < data->map->max_height * MAPCELL)
	{
		ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		while (data->map->map[ray->cell_x][ray->cell_y] != '1'
			&& data->map->map[ray->cell_x][ray->cell_y] != ' ')
		{
			ray->delta_y += MAPCELL;
			ray->delta_x = ray->delta_y * (-tan (angle));
			if ((int)(*player)->x + ray->delta_x < 0 || (int)(*player)->x
				+ ray->delta_x > data->map->max_height * MAPCELL)
				return (-1);
			ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
			i = sqrt(pow(ray->delta_y, 2) + pow(ray->delta_x, 2));
		}
	}
	return (i);
}
