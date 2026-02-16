/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:35:11 by rapohlen          #+#    #+#             */
/*   Updated: 2026/02/16 01:39:40 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add microseconds to time
struct timeval	ft_time_add(struct timeval time, unsigned int usec)
{
	time.tv_sec += usec / 1000000;
	time.tv_usec += usec % 1000000;
	return (time);
}
