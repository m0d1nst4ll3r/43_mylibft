/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:08:37 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/10 14:20:15 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*array;
	size_t	i;

	if (!s)
		return (NULL);
	array = (char *)s;
	i = 0;
	while (i < n)
	{
		if (array[i] == (char)c)
			return (array + i);
		i++;
	}
	return (NULL);
}
