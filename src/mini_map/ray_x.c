/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:13:47 by fausto            #+#    #+#             */
/*   Updated: 2022/09/08 09:27:34 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ray_x_ne(t_map *map, t_player **player, t_ray *ray, int *i)
{
	ray->delta_x = (int)(*player)->x % MAPCELL;
	ray->delta_y = ray->delta_x / tan(ray->angle);
	if (is_in_range(map, player, ray) == 0)
	{
		ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		while (ray->cell_x - 1 >= 0 && ray->cell_x - 1 <= map->max_height
			&& ray->cell_y >= 0 && ray->cell_y <= map->max_line
			&& map->map[ray->cell_x - 1][ray->cell_y] != '1'
			&& map->map[ray->cell_x - 1][ray->cell_y] != ' ')
		{
			ray->delta_x += MAPCELL;
			ray->delta_y = ray->delta_x / tan(ray->angle);
			if ((int)(*player)->y + ray->delta_y > map->max_line
				* MAPCELL || (int)(*player)->y + ray->delta_y < 0)
				return ((*i) = -1);
			(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
			ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		}
	}
}

static int	ray_x_nw(t_map *map, t_player **player, t_ray *ray, int *i)
{
	ray->delta_x = (int)(*player)->x % MAPCELL;
	ray->delta_y = ray->delta_x / -tan(ray->angle);
	if (is_in_range(map, player, ray) == 0)
	{
		ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		while (ray->cell_x - 1 >= 0 && ray->cell_y >= 0
			&& map->map[ray->cell_x - 1][ray->cell_y]
			&& (map->map[ray->cell_x - 1][ray->cell_y] != '1'
			&& map->map[ray->cell_x - 1][ray->cell_y] != ' '))
		{
			ray->delta_x += MAPCELL;
			ray->delta_y = ray->delta_x / -tan(ray->angle);
			if ((int)(*player)->y - ray->delta_y > map->max_line
				* MAPCELL || (int)(*player)->y - ray->delta_y < 0)
				return ((*i) = -1);
			(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
			ray->cell_x = ((int)(*player)->x - ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		}
	}
}

static int	ray_x_sw(t_map *map, t_player **player, t_ray *ray, int *i)
{
	ray->delta_x = MAPCELL - ((int)(*player)->x % MAPCELL);
	ray->delta_y = ray->delta_x / tan(ray->angle);
	if (is_in_range(map, player, ray) == 0)
	{
		ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		while (ray->cell_x >= 0 && ray->cell_x <= map->max_height
			&& ray->cell_y >= 0 && ray->cell_y <= map->max_line
			&& map->map[ray->cell_x][ray->cell_y] != '1'
			&& map->map[ray->cell_x][ray->cell_y] != ' ')
		{
			ray->delta_x += MAPCELL;
			ray->delta_y = ray->delta_x / tan(ray->angle);
			if ((int)(*player)->y - ray->delta_y > map->max_line
				* MAPCELL || (int)(*player)->y - ray->delta_y < 0)
				return ((*i) = -1);
			(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
			ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y - ray->delta_y) / MAPCELL;
		}
	}
}

static int	ray_x_se(t_map *map, t_player **player, t_ray *ray, int *i)
{
	ray->delta_x = MAPCELL - ((int)(*player)->x % MAPCELL);
	ray->delta_y = ray->delta_x / -tan(ray->angle);
	if (is_in_range(map, player, ray) == 0)
	{
		ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
		ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
		while (ray->cell_x >= 0 && ray->cell_x <= map->max_height
			&& ray->cell_y >= 0 && ray->cell_y <= map->max_line
			&& map->map[ray->cell_x][ray->cell_y] != '1'
			&& map->map[ray->cell_x][ray->cell_y] != ' ')
		{
			ray->delta_x += MAPCELL;
			ray->delta_y = ray->delta_x / -tan(ray->angle);
			if ((int)(*player)->y + ray->delta_y > map->max_line
				* MAPCELL || (int)(*player)->y + ray->delta_y < 0)
				return ((*i) = -1);
			(*i) = sqrt(pow(ray->delta_x, 2) + pow(ray->delta_y, 2));
			ray->cell_x = ((int)(*player)->x + ray->delta_x) / MAPCELL;
			ray->cell_y = ((int)(*player)->y + ray->delta_y) / MAPCELL;
		}
	}
}

int	ray_x(t_map *map, t_player **player, t_ray *ray)
{
	int	i;

	i = -1;
	if (ray->angle > 0 && ray->angle <= PI / 2)
		ray_x_ne(map, player, ray, &i);
	else if (ray->angle > (PI / 2) && ray->angle < PI)
		ray_x_nw(map, player, ray, &i);
	else if (ray->angle > PI && ray->angle <= 3 * ((2 * PI) / 4))
		ray_x_sw(map, player, ray, &i);
	else if (ray->angle > 3 * ((2 * PI) / 4) && ray->angle < 2 * PI)
		ray_x_se(map, player, ray, &i);
	else if (ray->angle == 0
		|| ray->angle == PI
		|| ray->angle == 2 * PI)
		return (-1);
	return (i);
}
