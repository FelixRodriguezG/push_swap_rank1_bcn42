/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:00:39 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/10 23:38:11 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Allocates memory (with malloc(3)) and returns a substring
 *	of the string ‘s’.
 *	The substring starts at index ‘start’ and has a maximum length
 *	of ‘len’.
 *	If start >= ft_strlen(s): returns an allocated empty string
 *	(ft_strdup("")), not NULL.
 *	Allocates only what is needed: min(len, ft_strlen(s) - start) + 1.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len +1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}

/*
** TEST FOR ft_substr
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_substr.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: ("hola mundo", 5, 5), ("hola mundo", 0, 4)
** - Edge cases: len larger than what remains, start == strlen(s),
**               start past the end of the string, len = 0, empty s,
**               len = SIZE_MAX (start + len overflows)
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, unsigned int start, size_t len,
		const char *expected)
{
	char	*ret;
	int		ok;

	ret = ft_substr(s, start, len);
	ok = (ret != NULL && strcmp(ret, expected) == 0);
	printf("[%s] %-34s ft: \"%s\"  expected: \"%s\"\n",
		ok ? "OK" : "KO", label, ret ? ret : "(NULL)", expected);
	if (!ok)
		g_ko++;
	free(ret);
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("(\"hola mundo\", 5, 5)", "hola mundo", 5, 5, "mundo");
	test("(\"hola mundo\", 0, 4)", "hola mundo", 0, 4, "hola");
	printf("--- edge cases ---\n");
	test("len larger than what remains", "hola mundo", 5, 100, "mundo");
	test("start == strlen(s)", "hola", 4, 3, "");
	test("start past the end of the string", "hola", 100, 3, "");
	test("len = 0", "hola", 1, 0, "");
	test("empty s", "", 0, 5, "");
	test("len = SIZE_MAX (start + len overflows)", "hola mundo", 5, SIZE_MAX,
		"mundo");
	printf("\nft_substr: %d KO (valgrind: allocation must match the result,"
		" not len)\n", g_ko);
	return (g_ko != 0);
}
*/
