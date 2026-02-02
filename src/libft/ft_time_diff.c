/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:56:06 by rapohlen          #+#    #+#             */
/*   Updated: 2026/02/02 16:22:03 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function returns the difference in MICROSECONDS between two timeval
//	variables (man gettimeofday).
// Since this returns an int, the most difference it can represent is 4294
//	seconds, or about 71 minutes and a half.
// The function is intended to work with small differences, for functions such
//	as refresh rate clocks.
// If the difference is too big, the function will simply return UINT_MAX.
unsigned int	ft_time_diff(struct timeval val, struct timeval sub)
{
	unsigned int	diff;

	if (val.tv_sec - sub.tv_sec > 4294)
		return (UINT_MAX);
	diff = 1000000 * (val.tv_sec - sub.tv_sec);
	if (diff == 4294000000 && val.tv_usec - sub.tv_usec > 967295)
		return (UINT_MAX);
	diff += val.tv_usec - sub.tv_usec;
	return (diff);
}
