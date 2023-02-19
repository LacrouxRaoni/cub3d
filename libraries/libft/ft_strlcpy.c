/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:18:02 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:18:02 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (dstsize > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		dstsize--;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
