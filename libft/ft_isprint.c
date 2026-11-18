/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:14:42 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 13:17:37 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
** TEST FOR ft_isprint
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_isprint.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'a', '~', ' ', '\n', '\t'
** - Edge cases: 31 (' ' - 1), 127 (DEL), 0 ('\0'), EOF (-1), 200 (byte > 127),
**               sweep -1..255 against libc
*/

/*
static int	g_ko = 0;

// The subject requires exactly 1 or 0; libc returns 1024, 2048... (0 / non-0)
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_isprint(c);
	libc = (isprint(c) != 0);
	printf("[%s] %-20s ft: %d  libc: %d\n",
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
		if (ft_isprint(c) != (isprint(c) != 0))
		{
			printf("     mismatch at c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] sweep -1..255 against isprint (%d differences)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'a'", 'a');
	test("'~'", '~');
	test("' '", ' ');
	test("'\\n'", '\n');
	test("'\\t'", '\t');
	printf("--- edge cases ---\n");
	test("31 (' ' - 1)", 31);
	test("127 (DEL)", 127);
	test("0 ('\\0')", 0);
	test("EOF (-1)", EOF);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_isprint: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
