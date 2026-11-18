/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 08:34:53 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/20 17:01:21 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
** TEST FOR ft_isalnum
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_isalnum.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'a', 'Z', '5', ' ', '!'
** - Edge cases: '0' - 1 ('/'), '9' + 1 (':'), 'A' - 1 ('@'), 'Z' + 1 ('['),
**               'a' - 1 ('`'), 'z' + 1 ('{'), EOF (-1), 200 (byte > 127),
**               sweep -1..255 against libc
*/

/*
static int	g_ko = 0;

// The subject requires exactly 1 or 0; libc returns 1024, 2048... (0 / non-0)
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_isalnum(c);
	libc = (isalnum(c) != 0);
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
		if (ft_isalnum(c) != (isalnum(c) != 0))
		{
			printf("     mismatch at c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] sweep -1..255 against isalnum (%d differences)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'a'", 'a');
	test("'Z'", 'Z');
	test("'5'", '5');
	test("' '", ' ');
	test("'!'", '!');
	printf("--- edge cases ---\n");
	test("'0' - 1 ('/')", '0' - 1);
	test("'9' + 1 (':')", '9' + 1);
	test("'A' - 1 ('@')", 'A' - 1);
	test("'Z' + 1 ('[')", 'Z' + 1);
	test("'a' - 1 ('`')", 'a' - 1);
	test("'z' + 1 ('{')", 'z' + 1);
	test("EOF (-1)", EOF);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_isalnum: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
