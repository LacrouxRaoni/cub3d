/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:17:23 by fausto            #+#    #+#             */
/*   Updated: 2022/09/01 11:11:04 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	file_extension(t_data *data, char *file, char *ext);
static void	file_access(t_data *data, char *file, char *ext);

void	file_validation(t_data *data, char *file, char *ext)
{
	if (file == NULL)
		exit_error(data, NULL, -2);
	file_extension(data, file, ext);
	file_access(data, file, ext);
}

static void	file_extension(t_data *data, char *file, char *ext)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (dot == NULL)
		exit_error(data, file, -2);
	if (ft_strncmp(dot, ext, 5) != 0)
		exit_error(data, file, -2);
}

static void	file_access(t_data *data, char *file, char *ext)
{
	if (access(file, R_OK) != 0)
	{
		if (ft_strncmp(ext, ".xpm", 4) == 0)
			ft_get_next_line(-1);
		exit_error(data, file, -3);
	}
}
