/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:10:46 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/19 15:22:26 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Array to short
// Almost as strict as atoi_strict
// But allows non-nul terminated numbers
// No '+', spaces, etc... allowed before number
int	ft_atos(char *s, short *n)
{
	int	neg;

	neg = 1;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (1);
	*n = 0;
	while (ft_isdigit(*s))
	{
		if (*n != (short)((unsigned short)*n * 10) / 10)
			return (1);
		*n = *n * 10 + neg * (*s - '0');
		if ((*n < 0 && neg > 0) || (*n > 0 && neg < 0))
			return (1);
		s++;
	}
	return (0);
}
