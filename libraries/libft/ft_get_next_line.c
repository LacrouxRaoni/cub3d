/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:17:40 by fagiusep          #+#    #+#             */
/*   Updated: 2022/08/01 17:47:36 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_prep_backup(char **backup)
{
	char		*temp;
	char		*line;
	size_t		i;

	i = 0;
	while ((*backup)[i] != '\n' && (*backup)[i] != '\0')
		i++;
	if ((*backup)[i] == '\n')
		i++;
	temp = *backup;
	line = ft_substr(temp, 0, i);
	*backup = ft_strdup(&(*backup)[i]);
	free(temp);
	return (line);
}

static int	gnl_read(int fd, char **backup, char **buff)
{
	int		r;
	char	*swap;

	r = 1;
	while (!ft_strchr(*backup, '\n') && r)
	{
		r = read(fd, *buff, BUFFER_SIZE);
		if (r < 0)
			return (r);
		(*buff)[r] = '\0';
		swap = *backup;
		*backup = ft_strjoin(swap, *buff);
		free(swap);
	}
	return (r);
}

static char	*gnl_prep_line(int fd, char **backup, char **buff)
{
	char	*temp;
	int		r;

	if (ft_strchr(*backup, '\n'))
		return (gnl_prep_backup(backup));
	r = gnl_read(fd, backup, buff);
	if (r <= 0 && !**backup)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (gnl_prep_backup(backup));
	if (!ft_strchr(*backup, '\n') && **backup)
	{
		temp = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (temp);
	}
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buff;

	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(backup);
		return (NULL);
	}
	buff = (char *)malloc(BUFFER_SIZE + 1);
	line = gnl_prep_line(fd, &backup, &buff);
	free(buff);
	buff = NULL;
	return (line);
}
