/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:37:13 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:38:45 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
** TEST FOR ft_putendl_fd
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_putendl_fd.c -L. -lft && ./a.out
**
** TEST CASES:
** - Demo: writes to the screen
** - Happy path: "hola" (adds the '\n')
** - Edge cases: "" (only the '\n'), "hola\n" (two newlines)
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
	ft_putendl_fd(s, fds[1]);
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
	ft_putendl_fd("hello on standard output (fd 1)", 1);
	ft_putendl_fd("hello on standard error (fd 2)", 2);
	printf("--- happy path ---\n");
	test("\"hola\" (adds the '\\n')", "hola", "hola\n");
	printf("--- edge cases ---\n");
	test("\"\" (only the '\\n')", "", "\n");
	test("\"hola\\n\" (two newlines)", "hola\n", "hola\n\n");
	printf("\nft_putendl_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
