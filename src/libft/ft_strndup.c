/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:54:32 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/27 16:48:58 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (len < n && s[len])
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
