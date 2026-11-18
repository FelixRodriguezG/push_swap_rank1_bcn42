/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:16:38 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:18:27 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

/*
** TEST FOR ft_putstr_fd
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_putstr_fd.c -L. -lft && ./a.out
**
** TEST CASES:
** - Demo: writes to the screen
** - Happy path: "hola" (no '\n')
** - Edge cases: "" (writes nothing), "a\nb" (with '\n' inside),
**               "ab\0cd" (stops at the \0)
*/

/*
static int	g_ko = 0;

// Writes to a pipe instead of the screen and reads what arrived
static void	test(char *label, char *s, const char *expected)
{
	int		fds[2];
	char	buf[50];
	int		bytes;
	int		ok;

	pipe(fds);
	ft_putstr_fd(s, fds[1]);
	close(fds[1]);
	bytes = read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	ok = (bytes == (int)strlen(expected)
			&& memcmp(buf, expected, bytes) == 0);
	printf("[%s] %-26s bytes written: %d (expected %d)\n",
		ok ? "OK" : "KO", label, bytes, (int)strlen(expected));
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- on-screen demo ---\n");
	ft_putstr_fd("hello on standard output (fd 1)\n", 1);
	ft_putstr_fd("hello on standard error (fd 2)\n", 2);
	printf("--- happy path ---\n");
	test("\"hola\" (no '\\n')", "hola", "hola");
	printf("--- edge cases ---\n");
	test("\"\" (writes nothing)", "", "");
	test("\"a\\nb\" (with '\\n' inside)", "a\nb", "a\nb");
	test("\"ab\\0cd\" (stops at the \\0)", "ab\0cd", "ab");
	printf("\nft_putstr_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
