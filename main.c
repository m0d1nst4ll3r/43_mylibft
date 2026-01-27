/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:10:57 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/27 14:00:33 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (0);
	if (ft_atox(av[1], BASE16, &i, 4 | ATOX_ZERO | ATOX_PREF))
		ft_printf("Returned error\n");
	else
		ft_printf("Result: %d\n", i);
}

/*
// FT_ATOX MACROS
// 17 Unsigned / Signed
# define ATOX_U		0x00010000
# define ATOX_S		0
// 18 Ignore base case
# define ATOX_CASE	0x00020000
// 19 Allow spaces
# define ATOX_SPA	0x00040000
// 20 Allow plus
# define ATOX_PLUS	0x00080000
// 21 Allow multi-sign
# define ATOX_MULT	0x00100000
// 22 Allow base prefix
# define ATOX_PREF	0x00200000
// 23 Allow preceding zeros
# define ATOX_ZERO	0x00400000
// 24 Allow absent number
# define ATOX_ABS	0x00800000
// 25 Allow trailing characters
# define ATOX_TR	0x01000000
// Allow all
# define ATOX_LAX	0x01fe0000
// Forbid all
# define ATOX_STRICT	0
*/
