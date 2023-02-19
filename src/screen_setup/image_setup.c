/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:40:41 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/09/01 11:43:50 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_img(t_data *data);
static void	get_img_addr(t_data *data);
static void	set_img_addr(t_data *data);

void	image_setup(t_data *data)
{
	create_img(data);
	get_img_addr(data);
}

static int	create_img(t_data *data)
{
	data->txtr.no.txtr = mlx_xpm_file_to_image(data->game->mlx_ptr,
			data->map->texture_no, &data->txtr.no.x, &data->txtr.no.y);
	data->txtr.so.txtr = mlx_xpm_file_to_image(data->game->mlx_ptr,
			data->map->texture_so, &data->txtr.so.x, &data->txtr.so.y);
	data->txtr.we.txtr = mlx_xpm_file_to_image(data->game->mlx_ptr,
			data->map->texture_we, &data->txtr.we.x, &data->txtr.we.y);
	data->txtr.ea.txtr = mlx_xpm_file_to_image(data->game->mlx_ptr,
			data->map->texture_ea, &data->txtr.ea.x, &data->txtr.ea.y);
}

static void	get_img_addr(t_data *data)
{
	data->txtr.no.addr = (int *)mlx_get_data_addr(data->txtr.no.txtr,
			&data->txtr.no.bits_per_pixel, &data->txtr.no.line_length,
			&data->txtr.no.endian);
	data->txtr.so.addr = (int *)mlx_get_data_addr(data->txtr.so.txtr,
			&data->txtr.so.bits_per_pixel, &data->txtr.so.line_length,
			&data->txtr.so.endian);
	data->txtr.we.addr = (int *)mlx_get_data_addr(data->txtr.we.txtr,
			&data->txtr.we.bits_per_pixel, &data->txtr.we.line_length,
			&data->txtr.we.endian);
	data->txtr.ea.addr = (int *)mlx_get_data_addr(data->txtr.ea.txtr,
			&data->txtr.ea.bits_per_pixel, &data->txtr.ea.line_length,
			&data->txtr.ea.endian);
}
