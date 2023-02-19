/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:02:51 by fausto            #+#    #+#             */
/*   Updated: 2022/08/26 16:45:29 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	file_error(t_data *data, char *str, int flag);
static void	infile_error(t_data *data, char *str, int flag);

void	exit_error(t_data *data, char *str, int flag)
{
	if (flag >= -3 && flag <= -1)
		file_error(data, str, flag);
	if (flag >= -11 && flag <= -4)
		infile_error(data, str, flag);
	if (flag > 0)
		clean(data);
	exit(1);
}

static void	file_error(t_data *data, char *str, int flag)
{
	if (flag == -1)
	{
		printf("Incorrect number of arguments!\n");
		exit(1);
	}
	if (flag == -2)
	{
		if (data->map->fd < 0)
			printf("%s file has incorrect extension.\n", str);
		if (data->map->fd > 0)
		{
			printf("%s texture has incorrect extension.\n", str);
			ft_get_next_line(-1);
		}
	}
	if (flag == -3)
	{
		if (errno == 13)
			printf("%s: Permission denied\n", str);
		if (errno == 2)
			printf("%s: No such file or directory\n", str);
	}
	free_map_struct(data);
	exit(flag);
}

static void	infile_error(t_data *data, char *str, int flag)
{
	if (flag == -4)
		printf("%s texture duplicated!\n", str);
	if (flag == -5)
		printf("Header argument missing!\n");
	if (flag == -6)
		printf("Invalid RGB color!\n");
	if (flag == -7)
		printf("Map error!\n");
	if (flag == -8)
		printf("%s: Map character not valid\n", str);
	if (flag == -9)
		printf("More than 1 player character on the map\n");
	if (flag == -10)
		printf("Map not closed with walls\n");
	ft_get_next_line(-1);
	free_map_struct(data);
	exit(flag);
}
