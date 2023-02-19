/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:14:57 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:14:57 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_elem;

	n_elem = (t_list *)malloc(sizeof(t_list));
	if (!n_elem)
		return (NULL);
	n_elem->content = content;
	n_elem->next = NULL;
	return (n_elem);
}
