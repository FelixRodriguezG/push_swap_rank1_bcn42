/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:02:01 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/05 16:20:06 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest > src)
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
** TEST FOR ft_memmove
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_memmove.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: no overlap (0..3 -> 5..8)
** - Edge cases: overlap, dst > src (0..5 -> 2..7),
**               overlap, dst < src (2..7 -> 0..5),
**               shift all right by 1, shift all left by 1,
**               dst == src, n = 0, copies across the \0
*/

/*
static int	g_ko = 0;

// Moves n bytes from buf + from to buf + to, in two identical buffers:
// one with ft_memmove and the other with memmove
static void	test(char *label, size_t to, size_t from, size_t n)
{
	char	ft[11];
	char	libc[11];
	void	*ret;
	int		ok;

	memcpy(ft, "0123456789", 11);
	memcpy(libc, "0123456789", 11);
	ret = ft_memmove(ft + to, ft + from, n);
	memmove(libc + to, libc + from, n);
	ok = (ret == ft + to && memcmp(ft, libc, 11) == 0);
	printf("[%s] %-36s ft: %s  libc: %s\n",
		ok ? "OK" : "KO", label, ft, libc);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	char	a[6];

	printf("--- happy path ---\n");
	test("no overlap (0..3 -> 5..8)", 5, 0, 4);
	printf("--- edge cases ---\n");
	test("overlap, dst > src (0..5 -> 2..7)", 2, 0, 6);
	test("overlap, dst < src (2..7 -> 0..5)", 0, 2, 6);
	test("shift all right by 1", 1, 0, 9);
	test("shift all left by 1", 0, 1, 9);
	test("dst == src", 3, 3, 4);
	test("n = 0", 2, 0, 0);
	memcpy(a, "-----", 6);
	ft_memmove(a, "a\0b\0", 4);
	printf("[%s] copies across the \\0\n",
		memcmp(a, "a\0b\0-", 6) == 0 ? "OK" : "KO");
	if (memcmp(a, "a\0b\0-", 6) != 0)
		g_ko++;
	printf("\nft_memmove: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
