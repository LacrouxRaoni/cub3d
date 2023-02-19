/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:17:15 by fausto            #+#    #+#             */
/*   Updated: 2022/10/17 15:31:26 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	chk_line(t_data *data, char **line, int *i);
static void	texture_validation(t_data *data, char **line, char **dir, char *s);

void	map_header_validation(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = ft_get_next_line(data->map->fd);
		if (!line)
			break ;
		if (chk_line(data, &line, &i) == 1)
		{
			break ;
		}
	}
}

static int	chk_line(t_data *data, char **line, int *i)
{
	if (ft_strncmp(*line, "NO ", 3) == 0)
		texture_validation(data, line, &data->map->texture_no, "NO");
	else if (ft_strncmp(*line, "SO ", 3) == 0)
		texture_validation(data, line, &data->map->texture_so, "SO");
	else if (ft_strncmp(*line, "WE ", 3) == 0)
		texture_validation(data, line, &data->map->texture_we, "WE");
	else if (ft_strncmp(*line, "EA ", 3) == 0)
		texture_validation(data, line, &data->map->texture_ea, "EA");
	else if (ft_strncmp(*line, "F ", 2) == 0)
		color_validation(data, line, &(data)->map->f);
	else if (ft_strncmp(*line, "C ", 2) == 0)
		color_validation(data, line, &(data)->map->c);
	else if (ft_strncmp(*line, "\n", 1) == 0)
	{
		free(*line);
		(*i)--;
	}
	else
	{
		free(*line);
		exit_error(data, NULL, -5);
	}
	(*i)++;
	return (0);
}

static void	texture_validation(t_data *data, char **line, char **dir, char *s)
{
	if (*dir != NULL)
	{
		free(*line);
		exit_error(data, s, -4);
	}
	*dir = get_value(*line);
	free(*line);
	line = NULL;
	file_validation(data, *dir, ".xpm");
	return ;
}

char	*get_value(char *line)
{
	int		start;
	int		end;
	char	*value;

	start = 0;
	while (line[start] != ' ')
		start++;
	while (line[start] == ' ')
		start++;
	if (line[start] == '\n')
		return (NULL);
	end = 0;
	while (line[start + end] != ' ' && line[start + end] != '\n')
		end++;
	value = ft_substr(line, start, end);
	return (value);
}
