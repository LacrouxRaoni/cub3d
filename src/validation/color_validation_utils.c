/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:14:13 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/10/18 10:33:26 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_color_value(char *line)
{
	int		start;
	int		end;
	char	*value;

	start = 0;
	end = 0;
	while (line[start] != ' ')
		start++;
	while (line[start] == ' ')
		start++;
	if (line[start] == '\n')
		return (NULL);
	while (line[start + end] != '\n')
		end++;
	value = ft_substr(line, start, end);
	return (value);
}

static int	count_str_in_line(char ***tmp_color, int i)
{
	int	k;
	int	j;

	j = -1;
	k = 0;
	while ((*tmp_color)[i][++j] != '\0')
	{
		if ((*tmp_color)[i][j] != ' ' && (*tmp_color)[i][j] != '\t')
			k++;
	}
	return (k);
}

void	clean_spaces_in_param(char ***tmp_color)
{
	int		i;
	int		j;
	int		k;
	char	*aux;

	i = -1;
	while ((*tmp_color)[++i])
	{
		k = count_str_in_line(tmp_color, i);
		aux = ft_calloc(sizeof(char *), k + 1);
		j = -1;
		k = -1;
		while ((*tmp_color)[i][++j] != '\0')
		{
			if ((*tmp_color)[i][j] != ' ' && (*tmp_color)[i][j] != '\t')
				aux[++k] = (*tmp_color)[i][j];
		}
		aux[++k] = '\0';
		free((*tmp_color)[i]);
		(*tmp_color)[i] = ft_strdup(aux);
		free(aux);
	}
}
