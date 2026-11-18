/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:40:57 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/07 21:34:17 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	target;

	src = (unsigned char *)s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*src == target)
			return ((void *)src);
		src++;
	}
	return (NULL);
}

/*
** TEST FOR ft_memchr
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_memchr.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'l' in "hola", 'o' in "hola hola" (the first one),
**               'z' in "hola" (not found)
** - Edge cases: searches for '\0', continues past \0 ("ab\0cd", 'c'),
**               'a' beyond n (n = 2), n = 0, byte 0xC8 searched as 200,
**               byte 0xC8 searched as -56, 'l' + 256 (truncated to 'l')
*/

/*
static int	g_ko = 0;

// Shows the position found (or NULL) by ft_memchr and by memchr
static void	test(char *label, const char *s, int c, size_t n)
{
	char	*ft;
	char	*libc;

	ft = ft_memchr(s, c, n);
	libc = memchr(s, c, n);
	printf("[%s] %-34s ft: ", ft == libc ? "OK" : "KO", label);
	if (ft)
		printf("s + %-4ld", (long)(ft - s));
	else
		printf("NULL    ");
	printf(" libc: ");
	if (libc)
		printf("s + %ld\n", (long)(libc - s));
	else
		printf("NULL\n");
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'l' in \"hola\"", "hola", 'l', 4);
	test("'o' in \"hola hola\" (the first one)", "hola hola", 'o', 9);
	test("'z' in \"hola\" (not found)", "hola", 'z', 4);
	printf("--- edge cases ---\n");
	test("searches for '\\0'", "hola", '\0', 5);
	test("continues past \\0 (\"ab\\0cd\", 'c')", "ab\0cd", 'c', 5);
	test("'a' beyond n (n = 2)", "hola", 'a', 2);
	test("n = 0", "hola", 'h', 0);
	test("byte 0xC8 searched as 200", "ab\xc8z", 200, 4);
	test("byte 0xC8 searched as -56", "ab\xc8z", -56, 4);
	test("'l' + 256 (truncated to 'l')", "hola", 'l' + 256, 4);
	printf("\nft_memchr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
