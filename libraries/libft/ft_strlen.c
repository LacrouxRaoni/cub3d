/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:18:10 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:18:10 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
