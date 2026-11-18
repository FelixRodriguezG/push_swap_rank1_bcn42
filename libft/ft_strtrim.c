/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:45:08 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/11 03:05:58 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief  Trims the characters in 'set' from the start and end of 's1'.
**
** @param  s1   Original string to be trimmed.
** @param  set  Set of characters to remove.
**
** @return Pointer to the new trimmed string (allocated with malloc),
**         or NULL if the allocation fails or the arguments are invalid.
**
** @note   - Advances 'start' from 0 while the character is in 'set'.
**         - Moves 'end' back from the end (ft_strlen) while the previous
**           character is in 'set'.
**         - If the whole string is trimmed (start >= end), ft_substr
**           takes care of returning an allocated empty string "".
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_len = end - start;
	return (ft_substr(s1, start, new_len));
}

/*
** TEST FOR ft_strtrim
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strtrim.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: ("  hola  ", " "), ("xxhola mundoxx", "x")
** - Edge cases: left side only, right side only,
**               middle ones are kept, everything is in set, empty set (copy),
**               empty s, last letter also in set
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, const char *set,
		const char *expected)
{
	char	*ret;
	int		ok;

	ret = ft_strtrim(s, set);
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
	test("(\"  hola  \", \" \")", "  hola  ", " ", "hola");
	test("(\"xxhola mundoxx\", \"x\")", "xxhola mundoxx", "x", "hola mundo");
	printf("--- edge cases ---\n");
	test("left side only", "  hola", " ", "hola");
	test("right side only", "hola  ", " ", "hola");
	test("middle ones are kept", " h o l a ", " ", "h o l a");
	test("everything is in set", "aaaa", "a", "");
	test("empty set (copy)", "  hola  ", "", "  hola  ");
	test("empty s", "", " ", "");
	test("last letter also in set", "ab hola ba", "ab ", "hol");
	printf("\nft_strtrim: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
