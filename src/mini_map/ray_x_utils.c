/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:13:26 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/09/08 09:25:25 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_range(t_map *map, t_player **player, t_ray *ray)
{
	if ((ray->angle > 0 && ray->angle <= PI / 2)
		|| (ray->angle > 3 * ((2 * PI) / 4) && ray->angle < 2 * PI))
	{
		if ((int)(*player)->y + ray->delta_y < map->max_line * MAPCELL
			|| (int)(*player)->y + ray->delta_y > 0)
			return (0);
	}
	else if ((ray->angle > (PI / 2) && ray->angle < PI)
		|| (ray->angle > PI && ray->angle <= 3 * ((2 * PI) / 4)))
	{
		if ((int)(*player)->y - ray->delta_y < map->max_line * MAPCELL
			|| (int)(*player)->y - ray->delta_y > 0)
			return (0);
	}
	return (1);
}
