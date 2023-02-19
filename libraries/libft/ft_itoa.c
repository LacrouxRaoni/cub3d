/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:13:12 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:13:12 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int num);
static char		*main_itoa(char *str, size_t n_digits, int n);

char	*ft_itoa(int n)
{
	size_t	n_digits;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	n_digits = ft_numlen(n);
	str = (char *)malloc((n_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	main_itoa(str, n_digits, n);
	return (str);
}

static size_t	ft_numlen(int num)
{
	size_t	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*main_itoa(char *str, size_t n_digits, int n)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[n_digits] = '\0';
	n_digits -= 1;
	while (n > 9)
	{
		str[n_digits] = (n % 10) + '0';
		n = n / 10;
		n_digits--;
	}
	if (n < 10)
		str[n_digits] = n + '0';
	return (str);
}
