/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:56:06 by rapohlen          #+#    #+#             */
/*   Updated: 2026/02/16 01:54:38 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return difference in usec
// If the subtraction results in integer overflow, behavior is undefined
int	ft_time_sub(struct timeval val, struct timeval sub)
{
	return (1000000 * (val.tv_sec - sub.tv_sec) + (val.tv_usec - sub.tv_usec));
}
