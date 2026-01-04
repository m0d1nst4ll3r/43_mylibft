/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 01:08:36 by rapohlen          #+#    #+#             */
/*   Updated: 2025/12/22 16:15:27 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LIBFT_WRITE_TIMEOUT	10
# define LIBFT_WRITE_DO_SLEEP	0
# define LIBFT_WRITE_USLEEP		1000

# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include "get_next_line.h"

int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *b, const char *l);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *d, const void *s, size_t n);

size_t	ft_strlcpy(char *d, const char *s, size_t n);
char	*ft_strcat(char *d, const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

void	ft_strlower(char *s);
void	ft_strupper(char *s);
void	ft_strrev(char *s);

int		ft_atoi(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);

int		ft_write(int fd, char *s, int len);
int		ft_atoi_strict(char *s, int *n);

#endif
