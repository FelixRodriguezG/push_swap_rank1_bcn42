/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:36:41 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/09 18:23:22 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first 'n' bytes of the memory areas 's1' and 's2'.
** Each byte is treated as an 'unsigned char' and compared one by one,
** from left to right.
**
** Returns:
** - An integer less than, equal to, or greater than zero if 's1' is,
**   respectively, less than, equal to, or greater than 's2'.
** - Zero (0) if the first 'n' bytes are identical or if 'n' is 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	if (n == 0)
		return (0);
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}

/*
** TEST FOR ft_memcmp
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_memcmp.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: "hola" vs "hola", "hola" vs "hole", "hole" vs "hola"
** - Edge cases: difference beyond n (n = 3), n = 0,
**               continues past \0 ("a\0b" vs "a\0c"),
**               unsigned: "\x80" vs "\x01", unsigned: "\xff" vs "\0"
*/

/*
static int	g_ko = 0;

static int	sign(int n)
{
	return ((n > 0) - (n < 0));
}

// Only the sign matters (-1, 0, 1), not the exact value
static void	test(char *label, const char *a, const char *b, size_t n)
{
	int	ft;
	int	libc;

	ft = sign(ft_memcmp(a, b, n));
	libc = sign(memcmp(a, b, n));
	printf("[%s] %-38s ft: %2d  libc: %2d\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"hola\" vs \"hola\"", "hola", "hola", 4);
	test("\"hola\" vs \"hole\"", "hola", "hole", 4);
	test("\"hole\" vs \"hola\"", "hole", "hola", 4);
	printf("--- edge cases ---\n");
	test("difference beyond n (n = 3)", "hola", "hole", 3);
	test("n = 0", "abc", "xyz", 0);
	test("continues past \\0 (\"a\\0b\" vs \"a\\0c\")", "a\0b", "a\0c", 3);
	test("unsigned: \"\\x80\" vs \"\\x01\"", "\x80", "\x01", 1);
	test("unsigned: \"\\xff\" vs \"\\0\"", "\xff", "\0", 1);
	printf("\nft_memcmp: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
