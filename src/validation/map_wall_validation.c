/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:14:50 by fausto            #+#    #+#             */
/*   Updated: 2022/11/29 11:46:56 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	define_column_line_size(t_data *data);
static void	complete_null_with_space(t_data *data);
static char	**turn_vert_to_horizon(t_data *data);

void	wall_validation(t_data *data)
{
	char	**map_vert;

	define_column_line_size(data);
	complete_null_with_space(data);
	map_vert = turn_vert_to_horizon(data);
	if (check_line(map_vert) == 1)
	{
		ft_split_free(map_vert);
		exit_error(data, NULL, -10);
	}
	if (check_line(data->map->map) == 1)
	{
		ft_split_free(map_vert);
		exit_error(data, NULL, -10);
	}
	ft_split_free(map_vert);
}

static void	define_column_line_size(t_data *data)
{
	int		i;
	char	**map;

	data->map->max_height = 0;
	data->map->max_line = 0;
	map = data->map->map;
	while (map[data->map->max_height])
	{
		i = 0;
		while (map[data->map->max_height][i] != '\0')
			i++;
		if (i > data->map->max_line)
			data->map->max_line = i;
		data->map->max_height++;
	}
}

static void	complete(t_data *data, int line_size, int i)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(data->map->map[i]);
	tmp2 = malloc(sizeof(char *) * (data->map->max_line - line_size));
	j = 0;
	while (line_size < data->map->max_line)
	{
		tmp2[j] = ' ';
		line_size++;
		j++;
	}
	tmp2[j] = '\0';
	free(data->map->map[i]);
	data->map->map[i] = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
}

static void	complete_null_with_space(t_data *data)
{
	int		line_size;
	int		i;

	i = 0;
	while (data->map->map[i])
	{
		line_size = ft_strlen(data->map->map[i]);
		if (line_size < data->map->max_line)
		{
			complete(data, line_size, i);
		}
		i++;
	}
}

static char	**turn_vert_to_horizon(t_data *data)
{
	char	*line;
	char	**map_vert;
	int		i;
	int		j;

	map_vert = NULL;
	map_vert = (char **)ft_calloc(data->map->max_line + 1, sizeof(char *));
	j = 0;
	while (j < data->map->max_line)
	{
		line = malloc(sizeof(char *) * data->map->max_height + 1);
		i = 0;
		while (i < data->map->max_height)
		{
			line[i] = data->map->map[i][j];
			i++;
		}
		line[i] = '\0';
		map_vert[j] = ft_strdup(line);
		free(line);
		j++;
	}
	return (map_vert);
}
