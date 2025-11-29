/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:36:49 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/27 11:18:06 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_printf *d, char *buf)
{
	while (*buf)
		write_buf(d, *buf++);
}

void	print_nstring(t_printf *d, char *buf, int n)
{
	int	i;

	i = 0;
	while (i++ < n && *buf)
		write_buf(d, *buf++);
}

void	print_upper(t_printf *d, char *buf)
{
	while (*buf)
	{
		if (*buf >= 'a' && *buf <= 'z')
			write_buf(d, *buf + ('A' - 'a'));
		else
			write_buf(d, *buf);
		buf++;
	}
}

void	print_char(t_printf *d, char c, int n)
{
	while (n)
	{
		write_buf(d, c);
		n--;
	}
}
