/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:11:48 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/11 16:24:45 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This is a safer version of write that looks at write's return.
// If write fails, return 1, if everything was written, return 0.
// If neither (partial success), try again a certain number of times.
int	ft_write(int fd, char *s, int len)
{
	int	ret;
	int	offset;
	int	attempts;

	attempts = 0;
	offset = 0;
	while (1)
	{
		ret = write(fd, input->line + offset, len);
		if (ret == len)
			return (1);
		else if (ret == -1 || ++attempts >= WR_TIMEOUT)
			return (1);
		else if (ret)
		{
			attempts = 0;
			offset += ret;
			len -= (size_t)ret;
		}
		if (LIBFT_WRITE_DO_SLEEP)
			usleep(LIBFT_WRITE_USLEEP);
	}
}
