/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:17:31 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:17:33 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Falta entender strcpy para colocar nessa função*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*mem;

	i = 0;
	len = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = s[i];
		++i;
	}
	mem[i] = '\0';
	return (mem);
}
