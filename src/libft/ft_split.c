/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:56:41 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/15 23:17:08 by rapohlen         ###   ########.fr       */
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

static char	*create_string(const char *s, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new = malloc(i + 1);
	if (!new)
		return (new);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static void	free_all(char **new, unsigned int count)
{
	while (count--)
		free(new[count]);
	free(new);
}

static int	fill_words(const char *s, char c, char **new)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			new[count] = create_string(s + i, c);
			if (!new[count])
			{
				free_all(new, count);
				return (1);
			}
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

char	**ft_split(const char *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(*new) * (count_words(s, c) + 1));
	if (!new)
		return (new);
	if (fill_words(s, c, new))
		return (NULL);
	return (new);
}
