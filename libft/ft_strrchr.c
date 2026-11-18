/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:07:55 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/07 17:12:55 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
		i++;
	while (1)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}

/*
** TEST FOR ft_strrchr
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strrchr.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 'o' in "hola hola" (the last one), 'z' in "hola" (absent)
** - Edge cases: 'h' only at position 0, 'a' at the last position,
**               '\0' (pointer to the terminator), 'a' in "", '\0' in "",
**               'o' + 256 (converted to 'o')
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, int c)
{
	char	*ft;
	char	*libc;

	ft = ft_strrchr(s, c);
	libc = strrchr(s, c);
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
	test("'o' in \"hola hola\" (the last one)", "hola hola", 'o');
	test("'z' in \"hola\" (absent)", "hola", 'z');
	printf("--- edge cases ---\n");
	test("'h' only at position 0", "hola", 'h');
	test("'a' at the last position", "hola", 'a');
	test("'\\0' (pointer to the terminator)", "hola", '\0');
	test("'a' in \"\"", "", 'a');
	test("'\\0' in \"\"", "", '\0');
	test("'o' + 256 (converted to 'o')", "hola hola", 'o' + 256);
	printf("\nft_strrchr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
