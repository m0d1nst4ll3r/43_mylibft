/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 01:27:44 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 15:56:44 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	if (!d || !s)
		return (d);
	dest = (char *)d;
	src = (char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (d);
}
