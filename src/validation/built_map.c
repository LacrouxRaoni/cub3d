/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:43:30 by fausto            #+#    #+#             */
/*   Updated: 2022/11/29 11:11:10 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_empty_file(char *line, t_data *data);
static int	validate_break_line(char *tmp);
static void	read_map_line(char **line, char **temp, t_data *data);

int	built_map(t_data *data)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = ft_get_next_line(data->map->fd);
	check_empty_file(line, data);
	while (*line == '\n')
	{
		free(line);
		line = ft_get_next_line(data->map->fd);
		if (line == NULL)
			exit_error(data, NULL, -7);
	}
	while (1)
	{
		read_map_line(&line, &temp, data);
		if (!line)
			break ;
	}
	if (validate_break_line(temp) == 1)
		return (1);
	data->map->map = ft_split(temp, '\n');
	free(temp);
	close(data->map->fd);
	return (0);
}

static void	check_empty_file(char *line, t_data *data)
{
	if (line == NULL)
		exit_error(data, NULL, -7);
}

static void	read_map_line(char **line, char **temp, t_data *data)
{
	char	*swap;

	swap = (*temp);
	(*temp) = ft_strjoin(swap, (*line));
	free(swap);
	free(*line);
	(*line) = ft_get_next_line(data->map->fd);
}

static int	validate_break_line(char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '\n')
		{
			if (tmp[i + 1] == '\n' && tmp[i + 2] == '1')
			{
				free (tmp);
				return (1);
			}
		}
	}
	return (0);
}
