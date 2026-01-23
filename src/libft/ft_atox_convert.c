/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:23:19 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/23 18:23:38 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert a value into its negative two's complement representation
// The value is contained in [size] bytes starting at address [var]
static void	negative(t_atox d)
{
	int	i;

	i = 0;
	while (i + 1 < d.varlen && !d.var[i])
	{
		d.var[i]--;
		i++;
	}
	d.var[i]--;
	i = 0;
	while (i < d.varlen)
	{
		d.var[i] = ~d.var[i];
		i++;
	}
}

// Adds a one-byte value [add] to another [size]-bytes value [var]
// Returns 1 if there was any overflow
static int	add(t_atox d, unsigned short add)
{
	int				i;

	i = 0;
	while (add && i < d.varlen)
	{
		add = d.var[i] + add;
		d.var[i] = (unsigned char)add;
		add = add >> 8;
		i++;
	}
	if (add || (d.is_signed && i == d.varlen && ((!d.neg && d.var[i - 1] > 127)
				|| (d.neg && d.var[i - 1] > 128))))
		return (1);
	return (0);
}

// Multiplies [size]-bytes [var] by one-byte [mult], byte-by-byte
// Returns 1 if there was any overflow
static int	mult(t_atox d, unsigned char mult)
{
	unsigned short	tmp;
	unsigned char	rest;
	int				i;

	i = 0;
	rest = 0;
	while (i < d.varlen)
	{
		tmp = d.var[i] * mult;
		d.var[i] = (unsigned char)tmp + rest;
		rest = tmp >> 8;
		i++;
	}
	if (rest || (d.is_signed && ((!d.neg && d.var[i - 1] > 127)
				|| (d.neg && d.var[i - 1] > 128))))
		return (1);
	return (0);
}

int	ft_atox_convert(t_atox *d)
{
	if (!d->skip_zeros && *d->str == *d->base)
		return (1);
	while (*d->str)
	{
		if (d->ignore_case)
			d->base_i = ft_strchr_case(d->base, *d->str);
		else
			d->base_i = ft_strchr(d->base, *d->str);
		if (!d->base_i)
			break ;
		if (!d->has_digit)
			d->has_digit = 1;
		if (mult(*d, d->baselen) || add(*d, d->base_i - d->base))
			return (1);
		d->str++;
	}
	if ((!d->has_digit && !d->nonum_ok) || (*d->str && !d->allow_extra))
		return (1);
	if (d->neg)
		negative(*d);
	return (0);
}
