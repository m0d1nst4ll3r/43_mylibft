/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:08:51 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 15:46:11 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_get_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	itoa_recurse(char *new, long n, int i)
{
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	if (n > 9)
		itoa_recurse(new, n / 10, i - 1);
	new[i] = n % 10 + '0';
}

char	*ft_itoa(t_libmlc **libmlc, int n)
{
	char	*new;
	int		len;

	len = itoa_get_len(n);
	new = libmlc_malloc(libmlc, len + 1);
	itoa_recurse(new, n, len - 1);
	new[len] = 0;
	return (new);
}
