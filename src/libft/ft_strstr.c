/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:14:44 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/27 14:52:32 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *b, const char *l)
{
	size_t	i;
	size_t	j;
	size_t	blen;
	size_t	llen;

	if (!b || !l)
		return (NULL);
	blen = ft_strlen(b);
	llen = ft_strlen(l);
	i = 0;
	while (blen - i >= llen)
	{
		j = 0;
		while (l[j] && b[i + j] == l[j])
			j++;
		if (!l[j])
			return ((char *)(b + i));
		i++;
	}
	return (NULL);
}
