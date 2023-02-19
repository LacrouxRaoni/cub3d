/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:09:49 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:09:49 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\r'
		|| c == '\n' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*ptr))
	{
		ptr++;
	}
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		res = (res * 10) + (*ptr - 48);
		ptr++;
	}
	return (sign * res);
}
