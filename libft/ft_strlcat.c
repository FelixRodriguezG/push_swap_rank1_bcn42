/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:26:37 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/05 23:15:00 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && len < maxlen)
		len++;
	return (len);
}

/*
** Appends 'src' to the end of 'dst', guaranteeing '\0' termination.
**
** SAFETY NOTE: 'ft_strnlen' is used to measure 'dst', limiting the read
** to 'siz' bytes. This avoids a segmentation fault if 'dst' has no '\0'
** within the range of the given buffer.
**
** @param dst  Destination buffer holding a null-terminated string.
** @param src  Source string to append.
** @param siz  Total size allocated for the destination buffer.
** @return     Total length it tried to create: strlen(src) + strlen(dst).
**             If siz <= strlen(dst), returns strlen(src) + siz.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strnlen(dst, siz);
	src_len = ft_strlen(src);
	if (siz <= dst_len)
		return (src_len + siz);
	i = dst_len;
	j = 0;
	while (src[j] && i < siz - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/*
** TEST FOR ft_strlcat
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_strlcat.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: "ho" + "la", size = 20
** - Edge cases: fits exactly (size = 5), truncates (size = 4),
**               size == strlen(dst) (size = 2), size < strlen(dst) (size = 1),
**               size = 0, empty src, empty dst
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *initial_dst, const char *src,
		size_t size, const char *expected_dst, size_t expected_ret)
{
	char	dst[20];
	size_t	ret;
	int		ok;

	memset(dst, 'X', 19);
	dst[19] = '\0';
	strcpy(dst, initial_dst);
	ret = ft_strlcat(dst, src, size);
	ok = (ret == expected_ret && strcmp(dst, expected_dst) == 0);
	printf("[%s] %-34s dst: \"%s\" (expected \"%s\")"
		"  ret: %zu (expected %zu)\n",
		ok ? "OK" : "KO", label, dst, expected_dst, ret, expected_ret);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"ho\" + \"la\", size = 20", "ho", "la", 20, "hola", 4);
	printf("--- edge cases ---\n");
	test("fits exactly (size = 5)", "ho", "la", 5, "hola", 4);
	test("truncates (size = 4)", "ho", "la", 4, "hol", 4);
	test("size == strlen(dst) (size = 2)", "ho", "la", 2, "ho", 4);
	test("size < strlen(dst) (size = 1)", "hola", "123", 1, "hola", 4);
	test("size = 0", "hola", "123", 0, "hola", 3);
	test("empty src", "hola", "", 20, "hola", 4);
	test("empty dst", "", "hola", 20, "hola", 4);
	printf("\nft_strlcat: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
