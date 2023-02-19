/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:15:00 by fausto            #+#    #+#             */
/*   Updated: 2022/11/29 11:18:32 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_three_param(char **color);
static int	is_digit(char **color);
static int	is_valid_digit(char **tmp_color, int **color);
static void	validation_error(t_data *data, char *tmp,
				char **tmp_color, char **line);

void	color_validation(t_data *data, char **line, int **color)
{
	char	*tmp;
	char	**tmp_color;

	tmp = get_color_value(*line);
	tmp_color = ft_split(tmp, ',');
	if (is_three_param(tmp_color) == 1)
		validation_error(data, tmp, tmp_color, line);
	clean_spaces_in_param(&tmp_color);
	if (is_digit(tmp_color) == 1)
		validation_error(data, tmp, tmp_color, line);
	if (is_valid_digit(tmp_color, color) == 1)
		validation_error(data, tmp, tmp_color, line);
	free(*line);
	free(tmp);
	ft_split_free(tmp_color);
}

static int	is_three_param(char **tmp_color)
{
	int	i;

	i = 0;
	while (tmp_color[i])
		i++;
	if (i != 3)
		return (1);
	return (0);
}

static int	is_digit(char **tmp_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tmp_color[i][j] != '\0')
		{
			if (ft_isdigit(tmp_color[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_digit(char **tmp_color, int **color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		(*color)[i] = ft_atoi(tmp_color[i]);
		if ((*color)[i] < 0 || (*color)[i] > 255)
			return (1);
		i++;
	}
	(*color)[3] = rgb_to_int((*color)[0], (*color)[1], (*color)[2]);
	return (0);
}

static void	validation_error(t_data *data, char *tmp,
			char **tmp_color, char **line)
{
	free(*line);
	free(tmp);
	ft_split_free(tmp_color);
	exit_error(data, NULL, -6);
}
