/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:56:41 by rapohlen          #+#    #+#             */
/*   Updated: 2026/05/30 16:50:32 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char *list)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_strchr(list, s[i]))
		{
			count++;
			while (s[i] && !ft_strchr(list, s[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*create_string(const char *s, char *list)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] && !ft_strchr(list, s[i]))
		i++;
	new = malloc(i + 1);
	if (!new)
		return (new);
	i = 0;
	while (s[i] && !ft_strchr(list, s[i]))
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

static int	fill_words(const char *s, char *list, char **new)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_strchr(list, s[i]))
		{
			new[count] = create_string(s + i, list);
			if (!new[count])
			{
				free_all(new, count);
				return (1);
			}
			count++;
			while (s[i] && !ft_strchr(list, s[i]))
				i++;
		}
		else
			i++;
	}
	new[count] = NULL;
	return (0);
}

char	**ft_ssplit(const char *s, char *list)
{
	char	**new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(*new) * (count_words(s, list) + 1));
	if (!new)
		return (new);
	if (fill_words(s, list, new))
		return (NULL);
	return (new);
}
