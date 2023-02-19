/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:39:03 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/12/06 17:29:43 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_data *data)
{
	data->game = ft_calloc(1, sizeof(t_game));
	data->game->win_height = 600;
	data->game->win_width = 800;
}
