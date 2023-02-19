/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:03:44 by fausto            #+#    #+#             */
/*   Updated: 2022/11/30 10:22:44 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean(t_data *data)
{
	mlx_destroy_image(data->game->mlx_ptr, data->game->img);
	mlx_destroy_image(data->game->mlx_ptr, data->txtr.no.txtr);
	mlx_destroy_image(data->game->mlx_ptr, data->txtr.so.txtr);
	mlx_destroy_image(data->game->mlx_ptr, data->txtr.we.txtr);
	mlx_destroy_image(data->game->mlx_ptr, data->txtr.ea.txtr);
	mlx_destroy_window(data->game->mlx_ptr, data->game->mlx_win);
	mlx_destroy_display(data->game->mlx_ptr);
	free(data->game->mlx_ptr);
	free(data->game);
	free(data->ray);
	free_map_struct(data);
	exit(0);
}

static void	free_data_map(t_data *data)
{
	int	i;

	i = -1;
	if (data->map->map != NULL)
	{
		while (data->map->map[++i])
			free(data->map->map[i]);
		free(data->map->map);
	}
	if (data->player != NULL)
		free(data->player);
}

static void	free_map_header(t_data *data)
{
	if (data->map->texture_no != NULL)
		free(data->map->texture_no);
	if (data->map->texture_so != NULL)
		free(data->map->texture_so);
	if (data->map->texture_we != NULL)
		free(data->map->texture_we);
	if (data->map->texture_ea != NULL)
		free(data->map->texture_ea);
	if (data->map->f != NULL)
		free(data->map->f);
	if (data->map->c != NULL)
		free(data->map->c);
}

void	free_map_struct(t_data *data)
{
	free_data_map(data);
	free_map_header(data);
	if (data->map->fd != -1)
		close(data->map->fd);
	free(data->map);
	exit(0);
}
