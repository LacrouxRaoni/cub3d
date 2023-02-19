/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_looping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:45:32 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:55 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	screen_pixel_put(t_data *data)
{
	int	i;

	i = data->game->win_width;
	while (--i >= 0)
	{
		ray_tracing(data, &(data->ray[i]), i);
	}
	ray_casting_wall(data);
	mlx_put_image_to_window(data->game->mlx_ptr,
		data->game->mlx_win, data->game->img, 0, 0);
	return (0);
}

static void	game_display(t_game **game)
{
	(*game)->mlx_ptr = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx_ptr,
			(*game)->win_width, (*game)->win_height, "CUB3D");
}

static void	game_image(t_data *data)
{
	data->game->img = mlx_new_image(data->game->mlx_ptr, data->game->win_width,
			data->game->win_height);
	data->game->addr = mlx_get_data_addr(data->game->img,
			&data->game->bits_per_pixel, &data->game->line_length,
			&data->game->endian);
	image_setup(data);
}

void	looping(t_data *data)
{
	game_display(&data->game);
	game_image(data);
	data->ray = ft_calloc(data->game->win_width, sizeof(t_ray));
	screen_pixel_put(data);
	mlx_hook(data->game->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->game->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->game->mlx_win, 17, 1L << 0, clean, data);
	mlx_loop_hook(data->game->mlx_ptr, screen_pixel_put, data);
	mlx_loop(data->game->mlx_ptr);
}
