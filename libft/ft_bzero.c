/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:10:14 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/24 11:19:07 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
** TEST FOR ft_bzero
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_bzero.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: n = 5, n = 10 (all)
** - Edge cases: n = 0 (touches nothing),
**               continues past a '\0' ("ab\0defghi", 6),
**               does not go past n (n = 1), int[4] to 0 with sizeof
*/

/*
static int	g_ko = 0;

// Compare the whole buffer with the result of libc's bzero
static void	test(char *label, const char *initial, size_t n)
{
	char	ft[10];
	char	libc[10];
	int		ok;

	memcpy(ft, initial, 10);
	memcpy(libc, initial, 10);
	ft_bzero(ft, n);
	bzero(libc, n);
	ok = (memcmp(ft, libc, 10) == 0);
	printf("[%s%s%s] %-34s buffer equal to bzero: %s%s%s\n",
		ok ? COLOR_GREEN : COLOR_RED,
		ok ? "OK" : "KO",
		COLOR_RESET,
		label,
		ok ? COLOR_GREEN : COLOR_RED,
		ok ? "yes" : "NO",
		COLOR_RESET);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	int		nums[4];
	int		expected[4];

	printf("--- happy path ---\n");
	test("n = 5", "abcdefghi", 5);
	test("n = 10 (all)", "abcdefghi", 10);
	printf("--- edge cases ---\n");
	test("n = 0 (touches nothing)", "abcdefghi", 0);
	test("continues past a '\\0' (\"ab\\0defghi\", 6)", "ab\0defghi", 6);
	test("does not go past n (n = 1)", "abcdefghi", 1);
	memset(expected, 0, sizeof(expected));
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	ft_bzero(nums, sizeof(nums));
	printf("[%s%s%s] int[4] to 0 with sizeof\n",
		memcmp(nums, expected, sizeof(nums)) == 0 ? COLOR_GREEN : COLOR_RED,
    	memcmp(nums, expected, sizeof(nums)) == 0 ? "OK" : "KO", COLOR_RESET);
	if (memcmp(nums, expected, sizeof(nums)) != 0)
		g_ko++;
	printf("\nKO's of ft_bzero: %s%d %s[KO's]%s\n", COLOR_CYAN, g_ko, COLOR_RED,
		COLOR_RESET);
	return (g_ko != 0);
}*/
