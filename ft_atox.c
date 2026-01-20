/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:14:10 by rapohlen          #+#    #+#             */
/*   Updated: 2026/01/20 12:41:03 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		ft_atox
 *
 *	« A marvel of engineering. » - Some Guy
 *		« It simply works. » - ft_atox comment section
 *
 * - Converts a string into a signed numerical value
 * - Accepts any base
 * - Accepts any type (char, short, int, intmax_t, custom type...)
 * - Wards against overflow
 * - It simply works
 *
 *	Args:
 * s		string to convert
 * base		base to convert in - if NULL, defaults to base 10
 * var		variable to write result in
 * size		size of the variable (e.g 4 for int - recommend using sizeof)
 *
 *	Return:
 * 0		Success - variable contains conversion result
 * 1		Failure - variable may contain anything
 * Failure happens if there is an overflow or if args are bad
*/
int	ft_atox(char *s, char *base, void *var, size_t size)
{
	if (!s || !var || !size)
		return (1);
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



// multiply value, start by assuming int
// OK - we've got byte-by-byte multiplication down
void	test2(void *sth, unsigned char mult)
{
	unsigned char	*a;
	int				tmp;
	int				rest;
	int				i;

	i = 0;
	rest = 0;
	a = sth;
	while (i < 4)
	{
		tmp = a[i] * mult;
		ft_printf("i[%d]: %d x %d = %d (binary %b) - casted value %b\n", i, a[i], mult, tmp, tmp, (char)tmp);
		a[i] = (char)tmp + rest;
		rest = tmp >> 8;
		ft_printf("rest is %b\n", rest);
		i++;
	}
}

void	test2_add(void *sth, unsigned char add)
{
	unsigned char	*a;
	int				tmp;
	int				rest;
	int				i;

	i = 0;
	a = sth;
	rest = 0;
	while (rest || (!i && !rest))
	{
		tmp = a[i] + add;
		a[i] = (char)tmp + rest;
		rest = tmp >> 8;
		i++;
	}
}

// NOW we need to add the new value, on the index
// Let's start with base 10 so it's easier
// s will only contain digits and be positive for now
// WORKS!!
void	test3(char *s, void *sth)
{
	unsigned char	*a;
	int				i;

	//need to fill sth with 0's
	ft_memset(sth, 0, 4);
	i = 0;
	a = sth;
	while (s[i])
	{
		// so here we need to mult and then add. for now we mult by 10, but later it will be baselen.
		// we mult the ENTIRE value by baselen, essentially we do what we did in test2 (we'll just be calling it here)
		// by the way... mult operation needs to tell us if we're trying to write too far into our value (overflow)
		// but then we also need to add the new thing
		// to add byte by byte, we just keep going until there is no rest
		// we need a loop like mult, and this ALSO needs to be protected against overflow.
		test2(sth, 10);
		test2_add(sth, s[i] - '0');
		i++;
	}
}

void	little_test(void *sth, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d: %hhb\n", i, ((char *)sth)[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (0);
	test3(av[1], &i);
	ft_printf("After test3: %d\n", i);
}
