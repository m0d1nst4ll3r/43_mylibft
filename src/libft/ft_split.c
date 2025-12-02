/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:56:41 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/02 15:44:40 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*create_string(t_libmlc **libmlc, const char *s, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new = libmlc_malloc(libmlc, i + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static int	fill_words(t_libmlc **libmlc, const char *s, char c, char **new)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			new[count] = create_string(libmlc, s + i, c);
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	new[count] = NULL;
	return (0);
}

char	**ft_split(t_libmlc **libmlc, const char *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = libmlc_malloc(libmlc, sizeof(*new) * (count_words(s, c) + 1));
	fill_words(libmlc, s, c, new);
	return (new);
}
