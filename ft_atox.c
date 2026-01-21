#include "libft.h"

#define BASE10 "0123456789"

// Multiplies var by mult, byte-by-byte
// For now, not detecting overflow. Later, will require size of var to be passed and return will be int to detect overflow.
// Defaulting to int size.
static int	mult(unsigned char *var, unsigned char mult, size_t size)
{
	short			tmp;
	unsigned char	rest;
	int				i;

	i = 0;
	rest = 0;
	while (i < size)
	{
		tmp = var[i] * mult;
		var[i] = (unsigned char)tmp + rest;
		rest = tmp >> 8;
		i++;
	}
	if (rest)
		return (1);
	return (0);
}

// Adds to var, byte-by-byte
// For now, not detecting overflow. Later, will require size of var to be passed and return will be int to detect overflow.
static int	add(unsigned char *var, unsigned short add, size_t size)
{
	int				i;

	i = 0;
	while (add)
	{
		if (i == size)
			return (1); // overflow
		add = var[i] + add;
		var[i] = (unsigned char)add;
		add = add >> 8;
		i++;
	}
	return (0);
}

// Reminder, we can handle base len up to 256, not 255

/*		ft_atox(char *to_convert, char *base, void *to_write, size_t type_size)
 *
 *	« A marvel of engineering. »	- Some Guy
 *		« It simply works. »	 - 'ft_atox' Comment Section
 *		  « Magnificent. »	  - Gandalf The White
 *
 * - Converts a string into a signed numerical value
 * - Accepts any base
 * - Accepts any type (char, short, int, intmax_t, custom type...)
 * - Wards against overflow
 * - It simply works
 *
 *	Args:
 * to_convert	string to convert
 * base			base to convert in - if NULL, defaults to base 10
 * to_write		variable to write result in
 * type_size	size of the variable (e.g 4 for int - recommend using sizeof)
 *
 *	Returns:
 * 0		Success - variable contains conversion result
 * 1		Failure - variable may contain anything
 * Failure happens if there is an overflow or if args are bad
 *
 *	To note:
 * - Preceding spaces, tabs etc... (isspace) are allowed
 * - Only one '-' or '+' sign is allowed
 * - If no digits are found, value defaults to 0 (and return is 0)
 * - Max base length is 256
 * .. See atox_strict for a stricter version
*/
int	ft_atox(char *s, char *base, void *var, size_t size)
{
	int	neg;
	int	i;
	int	baselen;

	// /!\   W.I.P !!!   /!\
	// For now, ignoring neg
	// For now, not testing overflow
	if (!s || !var || !size)
		return (1);
	if (!base)
		base = BASE10;
	baselen = ft_strlen(base);
	if (baselen > 256)
		baselen = 256;
	ft_memset(var, 0, size);
	i = 0;
	neg = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
		if (s[i] == '-')
			neg = -1;
	}
	while (s[i] && ft_strchr(base, s[i]))
	{
		if (mult(var, baselen, size) || add(var, ft_strchr(base, s[i]) - base, size))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (0);
	if (ft_atox(av[1], 0, &i, 4))
		ft_printf("Returned error\n");
	else
		ft_printf("Result: %d\n", i);
}
