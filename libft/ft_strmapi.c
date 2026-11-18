/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 08:26:50 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 08:47:36 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
char	rot_case(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper((unsigned char)c));
	return (tolower((unsigned char)c));
}

int main()
{
	char	*str = "hello world!";
	char	*res1;

	printf("Original string: \"%s\"\n\n", str);
	res1 = ft_strmapi(str, rot_case);
	printf("Test1 - ALTERNATES UPPER AND LOWER CASE:\n \t >>>\"%s\"\n", res1);
	free(res1);
	return (0);
}*/

/*
** TEST FOR ft_strmapi
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strmapi.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: returns "HOLA"
** - Edge cases: correct index i ("abcd"), it is a new string,
**               the original is unchanged, empty string -> allocated ""
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

static char	add_index(unsigned int i, char c)
{
	return (c + i);
}

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	original[5];
	char	*ret;

	strcpy(original, "aaaa");
	printf("--- happy path ---\n");
	ret = ft_strmapi("hola", to_upper);
	printf("     ft_strmapi(\"hola\", to_upper) = \"%s\"\n", ret);
	check(ret && strcmp(ret, "HOLA") == 0, "returns \"HOLA\"");
	free(ret);
	printf("--- edge cases ---\n");
	ret = ft_strmapi(original, add_index);
	printf("     ft_strmapi(\"aaaa\", add_index) = \"%s\"\n", ret);
	check(ret && strcmp(ret, "abcd") == 0, "correct index i (\"abcd\")");
	check(ret != original, "it is a new string");
	check(strcmp(original, "aaaa") == 0, "the original is unchanged");
	free(ret);
	ret = ft_strmapi("", add_index);
	check(ret && ret[0] == '\0', "empty string -> allocated \"\"");
	free(ret);
	printf("\nft_strmapi: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
