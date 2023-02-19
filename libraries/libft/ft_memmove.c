/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:16:08 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:16:08 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = n ;
	if (d > s)
	{
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
