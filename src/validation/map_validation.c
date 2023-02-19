/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:08:34 by fausto            #+#    #+#             */
/*   Updated: 2022/11/30 10:29:01 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	chars_validation(t_data *data);
static void	player_validation(t_data *data);
static void	player_setup(t_data *data, int x, int y);

void	map_validation(t_data *data)
{
	if (built_map(data) == 1)
		exit_error(data, NULL, -7);
	chars_validation(data);
	player_validation(data);
	wall_validation(data);
}

static void	chars_validation(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->map->map;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr(VALID_CHAR, map[x][y]) == NULL)
				exit_error(data, &map[x][y], -8);
			y++;
		}
		x++;
	}
}

void	player_validation(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->map->map;
	data->map->player = 'I';
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (data->map->map[x][y] != '0' && data->map->map[x][y] != '1'
				&& data->map->map[x][y] != ' ')
			{
				if (data->map->player == 'I')
					player_setup(data, x, y);
				else
					exit_error(data, &data->map->map[x][y], -9);
			}
		}
	}
	if (data->map->player == 'I')
		exit_error(data, NULL, -7);
}

static void	player_setup(t_data *data, int x, int y)
{
	data->map->player = data->map->map[x][y];
	data->player->x = (x * MAPCELL) + (MAPCELL / 2);
	data->player->y = (y * MAPCELL) + (MAPCELL / 2);
	data->player->cell_x = (int)data->player->x / MAPCELL;
	data->player->cell_y = (int)data->player->y / MAPCELL;
	if (data->map->map[x][y] == 'E')
		data->player->angle = 4 * (2 * PI / 4);
	else if (data->map->map[x][y] == 'W')
		data->player->angle = 2 * (2 * PI / 4);
	else if (data->map->map[x][y] == 'N')
		data->player->angle = 1 * (2 * PI / 4);
	else if (data->map->map[x][y] == 'S')
		data->player->angle = 3 * (2 * PI / 4);
	data->map->map[x][y] = '0';
}
