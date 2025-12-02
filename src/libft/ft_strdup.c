/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:09:17 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 15:43:39 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(t_libmlc **libmlc, const char *s)
{
	size_t	i;
	char	*new;

	new = libmlc_malloc(libmlc, ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
