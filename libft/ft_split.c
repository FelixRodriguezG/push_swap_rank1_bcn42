/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 03:10:35 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/13 00:46:42 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		**free_tab(char **tab, size_t i);
static size_t	word_len(char const *s, char c);
static char		*get_word(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			tab[i] = get_word(s, c);
			if (!tab[i])
				return (free_tab(tab, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

/*
* Counts the number of words in the string 's' delimited by the
* character 'c'.
*/
static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	short	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

/*
* Frees all memory previously allocated in the array 'tab' up to
* position 'i'.
*/
static char	**free_tab(char **tab, size_t i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

/*
** Computes the length of a single word starting at 's'
** until the delimiter character 'c' or the null terminator
*  '\0' is found.
*/
static size_t	word_len(char const *s, char c)
{
	size_t	w_len;

	w_len = 0;
	while (s[w_len] != c && s[w_len])
		w_len++;
	return (w_len);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = word_len(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

/*
** TEST FOR ft_split
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_split.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: ("hola que tal", ' ')
** - Edge cases: leading and trailing separators, repeated separators,
**               no separator, 1-character words, only separators,
**               empty string, c = '\0' (the whole string)
*/

/*
static int	g_ko = 0;

static void	free_result(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

// expected is a NULL-terminated array of words, like the result
static void	test(char *label, const char *s, char c, char **expected)
{
	char	**ret;
	int		i;
	int		ok;

	ret = ft_split(s, c);
	ok = (ret != NULL);
	i = 0;
	while (ok && expected[i])
	{
		if (!ret[i] || strcmp(ret[i], expected[i]) != 0)
			ok = 0;
		i++;
	}
	if (ok && ret[i] != NULL)
		ok = 0;
	printf("[%s] %-32s ft: {", ok ? "OK" : "KO", label);
	i = 0;
	while (ret && ret[i])
		printf("\"%s\", ", ret[i++]);
	printf("NULL}\n");
	if (!ok)
		g_ko++;
	free_result(ret);
}

int	main(void)
{
	char	*three[] = {"hola", "que", "tal", NULL};
	char	*one[] = {"hola", NULL};
	char	*short_words[] = {"a", "b", "c", NULL};
	char	*none[] = {NULL};
	char	*whole[] = {"hola que tal", NULL};

	printf("--- happy path ---\n");
	test("(\"hola que tal\", ' ')", "hola que tal", ' ', three);
	printf("--- edge cases ---\n");
	test("leading and trailing separators", "  hola que tal  ", ' ', three);
	test("repeated separators", "hola   que    tal", ' ', three);
	test("no separator", "hola", ' ', one);
	test("1-character words", "a,b,,c", ',', short_words);
	test("only separators", "     ", ' ', none);
	test("empty string", "", ' ', none);
	test("c = '\\0' (the whole string)", "hola que tal", '\0', whole);
	printf("\nft_split: %d KO (run it through valgrind: 0 leaks)\n", g_ko);
	return (g_ko != 0);
}
*/
