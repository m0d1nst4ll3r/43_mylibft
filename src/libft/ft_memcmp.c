/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:12:23 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 17:02:49 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*array1;
	unsigned char	*array2;
	size_t			i;

	if (!s1 || !s2 || !n)
		return (0);
	array1 = (unsigned char *)s1;
	array2 = (unsigned char *)s2;
	i = 0;
	while (i + 1 < n && array1[i] == array2[i])
		i++;
	return (array1[i] - array2[i]);
}
