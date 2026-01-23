#include "libft.h"

// Multiplies var by mult, byte-by-byte
// Detects overflow depending on sign
static int	mult(unsigned char *var, unsigned char mult, unsigned short size)
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
// Detects overflow depending on sign
static int	add(unsigned char *var, unsigned short add, unsigned short size)
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

// Returns NULL if error
static char	*skip_parse(char *s, int baselen, int params, int *neg)
{
	return (s);
}

/*		ft_atox(char *to_convert, char *base, void *to_write, int params)
 *
 * - Converts a string into a signed or unsigned numerical value
 * - Accepts any base (up to 255 length)
 * - Accepts any type (char, intmax_t, custom type... up to 65535 length)
 * - Wards against overflow, no matter the type, signed/unsigned
 * - Flexible, can tell it to behave one way or another when parsing string
 *	(skip spaces or not, allow multiple preceding signs or not, etc...)
 *
 *	Example usage:
 * ft_atox(str, NULL, &var, sizeof(var) | ATOX_LAX);
 * ft_atox(str, "0123456789abcdef", &var, sizeof(var) | ATOX_U | ATOX_CASE);
 *
 *	Args:
 * to_convert	string to convert
 * base			base to convert from - if NULL, defaults to base 10
 * to_write		address of variable to write result in
 * params		size of the variable + params (encoded as one value)
 *
 *	Params:
 * Params contain, in the following bits:
 * 1-16
 *	The variable's size in short form (recommend using sizeof())
 * 17
 *	0 ATOX_S	Signed conversion
 *	1 ATOX_U	Unsigned conversion (any preceding '-' is invalid)
 * 18
 *	0 (default)	Base case is respected
 *	1 ATOX_CASE	Base case is ignored (in hex base, 'a' and 'A' are both valid)
 * 19
 *	0 (default)	Preceding spaces are invalid
 *	1 ATOX_SPA	Preceding spaces are skipped (as defined by isspace)
 * 20
 *	0 (default)	Preceding '+' is invalid
 *	1 ATOX_PLUS	Preceding '+' is skipped
 * 21
 *	0 (default)	Multiple '+' and '-' are invalid
 *	1 ATOX_MULT	Multiple '+' are skipped and '-' are read (if signed)
 * 22
 *	0 (default)	Preceding base prefix is invalid (e.g "0x" "0b")
 *	1 ATOX_PREF	Preceding base prefix is skipped (depending on base length)
 * 23
 *	0 (default)	Preceding zeros are invalid (unless base prefix)
 *	1 ATOX_ZERO	Preceding zeros are skipped
 * 24
 *	0 (default)	Absent number is invalid
 *	1 ATOX_ABS	Absent number is treated as a 0
 * 25
 *	0 (default)	Trailing non-base characters are invalid
 *	1 ATOX_TR	Trailing non-base characters are skipped
 * The default behavior (no bit set) is to strictly read base digits
 *	(and one preceding '-') as a signed value, and consider any extra
 *	character as invalid. Use ATOX_STRICT to explicit this.
 * Use ATOX_LAX to set all bits (except signed/unsigned) to 1.
 *
 *	Returns:
 * 0		Success - The string is valid and the variable contains the result
 * 1		Failure - The string is invalid (see reasons), the var may contain
 * 						anything.
 *
 *	Possible reasons for failure:
 * 1. One or several args were bad (e.g NULL pointer)
 * 2. The string's value overflowed the desired type's size
 * 3. The string contained invalid characters according to params
 *
 *	Notes:
 * - Bases cannot contain '-' and '+' unless they were disabled in params
 * - A preceding '-' is always invalid when reading an unsigned value
 * - Max base length is 255
 * - Max variable size is 65535
*/
int	ft_atox(char *s, char *base, void *var, int params)
{
	int	neg;
	int	baselen;

	if (!s || !var || !(short)params)
		return (1);
	if (!base)
		base = BASE10;
	baselen = ft_strlen(base);
	if (baselen > 256)
		return (1);
	neg = 0;
	s = skip_parse(s, baselen, params, &neg);
	if (!s)
		return (1);
	ft_memset(var, 0, (short)params);
	while (*s && ((params & ATOX_CASE && ft_strchr_case(base, *s))
			|| ft_strchr(base, *s)))
	{
		if (mult(var, baselen, (short)params)
			|| add(var, ft_strchr(base, *s) - base, (short)params))
			return (1);
		s++;
	}
	return (0);
}

// Ok big changes
// Now I have to take all the options I just created into account
//
// Also, overflow testing will be different based on sign. If unsigned, it's pretty easy.
// The difficulty will be signed.
//
//
// Let's start with params
// So this is just a lot of parsing
//
// 1. Spaces
// 2. Plus/minus (multiple?)
// 3. Base prefix (if base good?)
// 4. Zeroes
// 5. Absent number?
// 6. Trailing characters?

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (0);
	ft_printf("%p\n", ft_strchr("bcdef", 'a'));
	if (ft_atox(av[1], 0, &i, 4))
		ft_printf("Returned error\n");
	else
		ft_printf("Result: %d\n", i);
}
