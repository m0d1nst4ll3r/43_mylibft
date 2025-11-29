/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 01:11:17 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 14:24:50 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*array;
	size_t	i;

	if (!s)
		return (s);
	i = 0;
	array = (char *)s;
	while (i < n)
	{
		array[i] = (char)c;
		i++;
	}
	return (s);
}
