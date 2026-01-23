/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:10:57 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/23 18:36:15 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	char	i;

	if (ac != 2)
		return (0);
	if (ft_atox(av[1], BASE16, &i, 1))
		ft_printf("Returned error\n");
	else
		ft_printf("Result: %hhd\n", i);
}
