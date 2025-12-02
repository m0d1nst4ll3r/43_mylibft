/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:42:16 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 15:57:06 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(t_libmlc **libmlc, const char *s, unsigned int start, size_t len)
{
	if (!s || ft_strlen(s) < start)
		return (NULL);
	return (ft_strndup(libmlc, s + start, len));
}
