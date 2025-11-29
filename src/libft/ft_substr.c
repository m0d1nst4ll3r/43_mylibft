/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:42:16 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 17:43:12 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*substr_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	new = malloc(len + 1);
	if (!new)
		return (new);
	ft_strlcpy(new, s, len + 1);
	return (new);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	if (!s || ft_strlen(s) < start)
		return (NULL);
	return (substr_strndup(s + start, len));
}
