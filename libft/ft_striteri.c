/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:04:41 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 09:14:36 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	f_toupper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	// 1. String on the stack -> no free() needed
	char	stack_str[] = "hello world!";

	printf("--- Test 1: Stack ---\n");
	printf("Before: %s\n", stack_str);
	ft_striteri(stack_str, f_toupper_even);
	printf("After:  %s\n\n", stack_str);

	// 2. String in dynamic memory (heap) -> free() required
	char	*heap_str = strdup("hello world!");

	if (heap_str)
	{
		printf("--- Test 2: Heap ---\n");
		printf("Before: %s\n", heap_str);
		ft_striteri(heap_str, f_toupper_even);
		printf("After:  %s\n", heap_str);
		
		// MANDATORY FREE to avoid leaks
		free(heap_str);
	}

	// 3. Edge cases (NULL) -> must not crash or do anything
	ft_striteri(NULL, f_toupper_even);
	ft_striteri(stack_str, NULL);

	return (0);
}*/

/*
** TEST FOR ft_striteri
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_striteri.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: modifies the string in place ("abcd"),
**               calls f once per character (4)
** - Edge cases: empty string: f is not called
*/

/*
static int	g_ko = 0;
static int	g_calls = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Takes a pointer to the character, so it can modify it in the string
static void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
	g_calls++;
}

int	main(void)
{
	char	s[5];
	char	empty[1];

	strcpy(s, "aaaa");
	printf("--- happy path ---\n");
	ft_striteri(s, add_index);
	printf("     \"aaaa\" after ft_striteri: \"%s\"\n", s);
	check(strcmp(s, "abcd") == 0, "modifies the string in place (\"abcd\")");
	check(g_calls == 4, "calls f once per character (4)");
	printf("--- edge cases ---\n");
	g_calls = 0;
	empty[0] = '\0';
	ft_striteri(empty, add_index);
	check(g_calls == 0, "empty string: f is not called");
	printf("\nft_striteri: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
