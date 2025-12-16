/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:57:58 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/16 18:58:21 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Only does digits, one '-' allowed, returns 0 for success
// Returns 1 if any bad char encountered or overflow
int	ft_atoi_strict(char *s, int *n)
{
	int	neg;

	neg = 1;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	if (!*s)
		return (1);
	*n = 0;
	while (*s >= '0' && *s <= '9')
	{
		if (*n != (int)((unsigned int)*n * 10) / 10)
			return (1);
		*n = *n * 10 + neg * (*s - '0');
		if ((*n < 0 && neg > 0) || (*n > 0 && neg < 0))
			return (1);
		s++;
	}
	if (*s)
		return (1);
	return (0);
}

