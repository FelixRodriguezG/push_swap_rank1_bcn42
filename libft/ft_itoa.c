/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 02:14:52 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/13 02:52:33 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_bytes(int n)
{
	long	num;
	size_t	count;

	num = (long)n;
	count = 1;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

static char	*fill_number(char *num, int n, size_t nbytes)
{
	size_t	i;
	long	number;

	i = nbytes - 1;
	number = (long)n;
	if (number < 0)
		number = -number;
	num[nbytes] = '\0';
	while (i > 0)
	{
		num[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	if (n < 0)
		num[i] = '-';
	else
		num[i] = number + '0';
	return (num);
}

char	*ft_itoa(int n)
{
	size_t	count_b;
	char	*number;

	count_b = count_bytes(n);
	if (n < 0)
		count_b++;
	number = (char *)malloc(sizeof(char) * (count_b + 1));
	if (!number)
		return (NULL);
	fill_number(number, n, count_b);
	return (number);
}

/*
** TEST FOR ft_itoa
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_itoa.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: 42, -42
** - Edge cases: 0, 9, 10, -10, 100, -5, 1000000000, INT_MAX, INT_MIN
*/

/*
static int	g_ko = 0;

// Compare with the output of sprintf, which does the same
static void	test(char *label, int n)
{
	char	*ft;
	char	expected[20];
	int		ok;

	ft = ft_itoa(n);
	sprintf(expected, "%d", n);
	ok = (ft != NULL && strcmp(ft, expected) == 0);
	printf("[%s] %-14s ft: \"%s\"  expected: \"%s\"\n",
		ok ? "OK" : "KO", label, ft ? ft : "(NULL)", expected);
	if (!ok)
		g_ko++;
	free(ft);
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("42", 42);
	test("-42", -42);
	printf("--- edge cases ---\n");
	test("0", 0);
	test("9", 9);
	test("10", 10);
	test("-10", -10);
	test("100", 100);
	test("-5", -5);
	test("1000000000", 1000000000);
	test("INT_MAX", INT_MAX);
	test("INT_MIN", INT_MIN);
	printf("\nft_itoa: %d KO (valgrind: exact allocation for each number)\n",
		g_ko);
	return (g_ko != 0);
}
*/
