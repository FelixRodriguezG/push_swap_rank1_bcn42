/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:58:09 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/08 09:21:20 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j) < len)
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*
** TEST FOR ft_strnstr
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strnstr.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: "mundo" in "hola mundo", "adios" in "hola mundo"
** - Edge cases: empty needle, empty needle with len = 0, len = 0,
**               needle cut by len (len = 9), needle fits exactly (len = 10),
**               partial match ("aab" in "aaab"),
**               needle longer than big, len greater than big
*/

/*
static int	g_ko = 0;

// expected_pos = -1 means NULL is expected
static void	test(char *label, const char *big, const char *little,
		size_t len, long expected_pos)
{
	char	*ret;
	long	pos;

	ret = ft_strnstr(big, little, len);
	pos = -1;
	if (ret)
		pos = (long)(ret - big);
	printf("[%s] %-38s ft: ", pos == expected_pos ? "OK" : "KO", label);
	if (pos == -1)
		printf("NULL    ");
	else
		printf("big + %-2ld", pos);
	if (expected_pos == -1)
		printf(" expected: NULL\n");
	else
		printf(" expected: big + %ld\n", expected_pos);
	if (pos != expected_pos)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"mundo\" in \"hola mundo\"", "hola mundo", "mundo", 10, 5);
	test("\"adios\" in \"hola mundo\"", "hola mundo", "adios", 10, -1);
	printf("--- edge cases ---\n");
	test("empty needle", "hola", "", 4, 0);
	test("empty needle with len = 0", "hola", "", 0, 0);
	test("len = 0", "hola", "h", 0, -1);
	test("needle cut by len (len = 9)", "hola mundo", "mundo", 9, -1);
	test("needle fits exactly (len = 10)", "hola mundo", "mundo", 10, 5);
	test("partial match (\"aab\" in \"aaab\")", "aaab", "aab", 4, 1);
	test("needle longer than big", "hola", "hola mundo", 20, -1);
	test("len greater than big", "hola", "la", 100, 2);
	printf("\nft_strnstr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
