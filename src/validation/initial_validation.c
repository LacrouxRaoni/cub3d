/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:12:33 by fausto            #+#    #+#             */
/*   Updated: 2022/11/30 10:29:13 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	prompt_(t_data *data, int argc);
static void	init_map_struct(t_data *data, char *file);

void	initial_validation(t_data *data, int argc, char *argv[])
{
	prompt_(data, argc);
	init_map_struct(data, argv[1]);
	file_validation(data, argv[1], ".cub");
	map_header_validation(data);
	map_validation(data);
}

static void	prompt_(t_data *data, int argc)
{
	if (argc != 2)
		exit_error(data, NULL, -1);
}

static void	init_map_struct(t_data *data, char *file)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->map->map = NULL;
	data->map->f = (int *)ft_calloc(4, sizeof(int));
	data->map->c = (int *)ft_calloc(4, sizeof(int));
	data->map->player = 'I';
	data->map->closed_wall = 0;
	data->map->fd = open(file, O_RDONLY);
	data->player = ft_calloc(1, sizeof(t_player));
}
