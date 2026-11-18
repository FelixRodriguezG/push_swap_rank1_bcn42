/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:15:46 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 16:17:11 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
** TEST FOR ft_tolower
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_tolower.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'A', 'Z', 'M'
** - Edge cases: 'a' (already lowercase), '5' (not a letter), 'A' - 1 ('@'),
**               'Z' + 1 ('['), EOF (-1), 0 ('\0'), 200 (byte > 127),
**               sweep -1..255 against libc
*/

/*
static int	g_ko = 0;

// Here the exact value does matter
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_tolower(c);
	libc = tolower(c);
	printf("[%s] %-20s ft: %4d  libc: %4d\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

static void	sweep(void)
{
	int	c;
	int	fails;

	fails = 0;
	c = -1;
	while (c <= 255)
	{
		if (ft_tolower(c) != tolower(c))
		{
			printf("     differs at c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] sweep -1..255 against tolower (%d differences)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'A'", 'A');
	test("'Z'", 'Z');
	test("'M'", 'M');
	printf("--- edge cases ---\n");
	test("'a' (already lowercase)", 'a');
	test("'5' (not a letter)", '5');
	test("'A' - 1 ('@')", 'A' - 1);
	test("'Z' + 1 ('[')", 'Z' + 1);
	test("EOF (-1)", EOF);
	test("0 ('\\0')", 0);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_tolower: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
