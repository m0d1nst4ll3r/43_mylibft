/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 01:08:36 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/28 11:37:16 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LIBFT_WRITE_TIMEOUT	10
# define LIBFT_WRITE_DO_SLEEP	0
# define LIBFT_WRITE_USLEEP		1000

# define BASE2		"01"
# define BASE8		"01234567"
# define BASE10		"0123456789"
# define BASE16		"0123456789abcdef"

// FT_ATOX MACROS
// 17 Unsigned / Signed
# define ATOX_U		0x00010000
# define ATOX_S		0
// 18 Ignore base case
# define ATOX_CASE	0x00020000
// 19 Allow spaces
# define ATOX_SPA	0x00040000
// 20 Allow plus
# define ATOX_PLUS	0x00080000
// 21 Allow multi-sign
# define ATOX_MULT	0x00100000
// 22 Allow base prefix
# define ATOX_PREF	0x00200000
// 23 Allow preceding zeros
# define ATOX_ZERO	0x00400000
// 24 Allow absent number
# define ATOX_ABS	0x00800000
// 25 Allow trailing characters
# define ATOX_TR	0x01000000
// Allow all
# define ATOX_LAX	0x01fe0000
// Forbid all
# define ATOX_STRICT	0

# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_atox
{
	char			*str;
	char			*base;
	char			*base_i;
	unsigned char	baselen;
	unsigned char	*var;
	unsigned short	varlen;
	int				params;
	int				neg;
	char			has_digit;
	char			is_signed;
	char			ignore_case;
	char			skip_spaces;
	char			skip_plus;
	char			multiple_signs;
	char			skip_prefix;
	char			skip_zeros;
	char			nonum_ok;
	char			allow_extra;
}	t_atox;

int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_ishexa(char c);
int		ft_islower(char c);
int		ft_isupper(char c);

int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strchr_case(char *s, char c);
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
void	ft_close(int *fd);
void	ft_select_sort(int *arr, int len);
void	ft_free(void **p);

// ft_atox extension
int		ft_atox_convert(t_atox *d, int *i);
int		ft_atox(char *s, char *base, void *var, int params);

#endif
