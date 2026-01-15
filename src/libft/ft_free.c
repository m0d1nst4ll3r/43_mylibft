/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:35:51 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/15 15:39:41 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Better free, does not syscall if address is already NULL and sets to NULL
void	ft_free(void **p)
{
	if (!p)
		return ;
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
