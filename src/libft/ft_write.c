/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:11:48 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/22 16:35:37 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This is a safer version of write that looks at write's return.
// If write fails, return -1, if everything was written, return 0.
// In case of partial success, retry a certain amount of times.
// After trying a certain amount of times and not succeeding at writing
//  anything, return 1.
int	ft_write(int fd, char *s, int len)
{
	int	ret;
	int	offset;
	int	attempts;

	if (!s || fd < 0 || len < 0)
		return (-1);
	attempts = 0;
	offset = 0;
	while (1)
	{
		ret = write(fd, s + offset, len - offset);
		if (ret == len - offset)
			return (0);
		if (ret < 0)
			return (-1);
		if (ret)
		{
			attempts = 0;
			offset += ret;
		}
		else if (++attempts >= LIBFT_WRITE_TIMEOUT)
			return (1);
		if (LIBFT_WRITE_DO_SLEEP)
			usleep(LIBFT_WRITE_USLEEP);
	}
}
