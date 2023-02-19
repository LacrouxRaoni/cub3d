/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:15:56 by fausto            #+#    #+#             */
/*   Updated: 2022/10/18 10:06:25 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	initial_validation(&data, argc, argv);
	init_game(&data);
	looping(&data);
	free_map_struct(&data);
	return (0);
}
