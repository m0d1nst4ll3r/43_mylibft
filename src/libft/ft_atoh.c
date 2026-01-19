/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:23:22 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/19 15:34:54 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// Atoi but for hex
int	ft_atoh(char *s)
{
	int		neg;
	int		res;

	res = 0;
	neg = 1;
	if (*s == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			neg = -1;
		s++;
	}
	while (get_index(*s, "0123456789abcdefABCDEF") != -1)
	{
		if (*s >= 'a' && *s <= 'f')
			res = res * 16 + neg * get_index(*s, "0123456789abcdef");
		else
			res = res * 16 + neg * get_index(*s, "0123456789ABCDEF");
		s++;
	}
	return (res);
}
