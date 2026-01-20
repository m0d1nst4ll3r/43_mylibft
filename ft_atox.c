/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:14:10 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/20 15:54:44 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE10 "0123456789"

// Multiplies var by mult, byte-by-byte
// For now, not detecting overflow. Later, will require size of var to be passed and return will be int to detect overflow.
// Defaulting to int size.
static void	mult(unsigned char *var, unsigned char mult)
{
	short			tmp;
	unsigned char	rest;
	int				i;

	i = 0;
	rest = 0;
	while (i < 4)
	{
		tmp = var[i] * mult;
		var[i] = (unsigned char)tmp + rest;
		rest = tmp >> 8;
		i++;
	}
}

// Adds to var, byte-by-byte
// For now, not detecting overflow. Later, will require size of var to be passed and return will be int to detect overflow.
static void	add(unsigned char *var, unsigned char add)
{
	unsigned short	to_add;
	unsigned char	rest;
	int				i;

	i = 0;
	rest = 0;
	to_add = var[i] + add;
	while (to_add)
	{
		var[i] = (unsigned char)to_add;
		rest = var[i + 1] + (to_add >> 8);
		i++;
	}
}

// A B C D
// Add
//
// Potentially, Add + D is > 255 = does not fit within a byte
// So, just write whatever fits, in there, then use rest
//
// Take 100090
// 1    1000 0110    1111 1010
// 1    134          250
// We want to add 9
// That would be
// 1    1000 0111    0000 0011
// 1    135          3
// Counting up 9 times
// 1011
// 1100
// 1101
// 1110
// 1111
// 1 0000 0000
// 1 0000 0001
// 1 0000 0010
// 1 0000 0011

/*		ft_atox(char *to_convert, char *base, void *to_write, size_t type_size)
 *
 *	« A marvel of engineering. » - Some Guy
 *		« It simply works. » - 'ft_atox' Comment Section
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
	ft_memset(var, 0, 4);
	baselen = ft_strlen(base);
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
		mult(var, baselen);
		ft_printf("Step %d: %d\n", i, *(int *)var);
		add(var, ft_strchr(base, s[i]) - base);
		ft_printf("Step %d: %d\n", i, *(int *)var);
		i++;
	}
	return (0);
}

// Good to know:
// When passing a variable of size N through its address and representing it as a list of chars,
// At index 0, the last byte (the 8 least significant bits) is contained.
// At index 1, the before-last byte (next 8 least significant bits) is contained.
// Etc...

// So, to write into our void *, we need to start writing at the beginning, conveniently enough.
// When do we swap to a new byte, though?
// Depends on the base?
// Base  2: 1111 1111 - that fits into a byte
// Base 10: 9999 9999 - that does NOT fit into a byte (only up to 255 fits)

// The regular way we do it in an atoi is taking the first digit and adding it to n * 10.
// In an atoi_base, we take the index of the first character in its base, add that value to n * baselen.
// E.g 123 we do 1, then 10 + 2, then 120 + 3
// Easy
// abc we would do index of a, 11, then 11 * 16 + index of b, 12, then (11 * 16 + 12) * 16 + 13
// So 11 * 16^2 + 12 * 16 + 13
// Pretty much what a base calculation is
// Here though, we want 2 things:
// 1. Test for overflow
// 2. Put the number in singular bytes, one byte at a time.
// 8 bits take up to 2^8 different values so starting at 0, 2^8 - 1 max value
// 2 base 10 digits take up to 10^2 values, 100 values (99 starting at 0)
// But 3 can already take more than 2^8
// Not to mention negative numbers. We also want to handle that.

// Writing bits directly is probably too hard and quite overkill
// We can probably make do with some basic arithmetic

// Let's look at 256 to start with
// 256 is a 1, then 8 0's
// If I work the same way as before, I'll first write 2 in my byte, then 25, but upon trying to write 256 I have to realize that that is too big a number to put in a single byte. I have to split it. My 0th byte will have 0 and my 1st will have 1. Combined, they'll be 256.
// How do I realize that 256 is too big to fit in a byte? If it's > 255, obviously. But if I want my function to use potentially infinite sizes, I can't assume that I'll be able to hold 256 in memory. Because that 256 could be a huge value, bigger than an intmax_t can hold.
// Also, my bases can be potentially enormous. I can set a manual limit, and work with something that'll work as long as my bases don't get too big.
// Then I can assume that whenever I add my next digit to a byte, I can hold that value and compare it to 255, recognize that it's bigger, and write to the next byte
// But when I add a digit to my number, if I'm multiplying everything by the base length, then I can't really hold that result in a variable
// Basically I need to do bit multiplication.
// Say I have 1001 and I want to multiply it to 0110
// How do I do that?
// I have to know how to multiply bits to move forward, I think
// Then I can just take the entire value (will be filled with 0's originally)
// And multiply it *manually* with the baselen

//     1001 -   9
//   x 0110 - x 6
// ------------
//  11 0110     54 (32 + 16 + 4 + 2)

// Ok look at this:
// I don't necessarily need to do any bitwise or bit multiplication myself
//
// Imagine bytes like this
// A B C D
// D is the least significant, A most significant
// If my base length is limited to 255, Why not multiply byte by byte, with an int
// A B C D
// x baselen (max 255) - fits in an unsigned char
// 1. Do D x baselen
// Result might overflow if > 255
// 2. Add result's last byte (ls) (a cast to char might just work) to D
// 3. Memorize result's before-last byte
// 4. Do C x baselen
// 5. Add result to memorized byte
// 6. Add final result's last byte (ls) to C
// 7. Memorize, etc...
// 8. Anytime you have to write to a byte outside your size, you know there's an overflow... except for negatives....... that's a problem.

// Have to figure out how to swap the bytes to negative. Just multiply each by -1?
// It's harder than flipping the bits. Imagining 0011 (3) as a signed demi-byte, its negative value (-3) is 1101
// Multiplying bytes by -1 does not look like it's gonna work. 3 in int is just a bunch of 0's then 11
// But -3 is all 1's then 01
// 0 times -1 stays 0 so that doesn't work

// Progress!

// Reminder, we can handle base len up to 256, not 255

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (0);
	ft_atox(av[1], 0, &i, 4);
	ft_printf("Result: %d\n", i);
}
