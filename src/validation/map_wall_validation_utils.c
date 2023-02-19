/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_validation_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:51:00 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/08/16 19:03:12 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char **line)
{
	char	**tmp;
	int		x;
	int		y;

	x = -1;
	while (line[++x])
	{
		tmp = ft_split(line[x], ' ');
		y = -1;
		while (tmp[++y])
		{
			if (tmp[y][0] != '1')
			{
				ft_split_free(tmp);
				return (1);
			}
			if (tmp[y][ft_strlen(tmp[y]) - 1] != '1')
			{
				ft_split_free(tmp);
				return (1);
			}
		}
		ft_split_free(tmp);
	}
	return (0);
}
