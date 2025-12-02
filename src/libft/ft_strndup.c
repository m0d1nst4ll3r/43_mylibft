/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:54:32 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 15:52:34 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(t_libmlc **libmlc, const char *s, size_t n)
{
	char	*new;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (len < n && s[len])
		len++;
	new = libmlc_malloc(libmlc, len + 1);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
