/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:19:22 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/07 20:43:16 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
** TEST FOR ft_strchr
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strchr.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'l' in "hola", 'o' in "hola hola" (the first one),
**               'z' in "hola" (not found)
** - Edge cases: '\0' (pointer to the terminator), 'a' in "", '\0' in "",
**               'h' (position 0), 'l' + 256 (converted to 'l'),
**               byte 0xE9 searched as 233, byte 0xE9 searched as (char)
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, int c)
{
	char	*ft;
	char	*libc;

	ft = ft_strchr(s, c);
	libc = strchr(s, c);
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
	test("'l' in \"hola\"", "hola", 'l');
	test("'o' in \"hola hola\" (the first one)", "hola hola", 'o');
	test("'z' in \"hola\" (not found)", "hola", 'z');
	printf("--- edge cases ---\n");
	test("'\\0' (pointer to the terminator)", "hola", '\0');
	test("'a' in \"\"", "", 'a');
	test("'\\0' in \"\"", "", '\0');
	test("'h' (position 0)", "hola", 'h');
	test("'l' + 256 (converted to 'l')", "hola", 'l' + 256);
	test("byte 0xE9 searched as 233", "caf\xe9", 0xe9);
	test("byte 0xE9 searched as (char)", "caf\xe9", (char)0xe9);
	printf("\nft_strchr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
