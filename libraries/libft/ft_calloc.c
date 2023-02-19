/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:10:14 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:10:14 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;

	tot_size = nmemb * size;
	pos = malloc(tot_size);
	if (!pos || (tot_size > INT_MAX))
		return (NULL);
	ft_bzero(pos, tot_size);
	return ((void *)pos);
}
