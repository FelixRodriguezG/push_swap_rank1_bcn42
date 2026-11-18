/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:25:59 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/20 16:59:56 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory for an array of elements and initializes all
 * bytes to zero.
 *
 * Checks for integer overflow using (nmemb > SIZE_MAX / size) to safely
 * prevent 'nmemb * size' from wrapping around before allocation. Allocates
 * 'nmemb * size' bytes using malloc and fills the allocated block with zero
 * bytes using ft_bzero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size  Size in bytes of each element.
 * @return void* Pointer to the allocated and zeroed memory, or NULL if
 *               allocation fails, if size parameters are invalid, or if an
 *               integer overflow is detected.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	num_bytes;

	if (size && nmemb && (nmemb > SIZE_MAX / size))
		return (NULL);
	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_bytes);
	return (ptr);
}

/*
** TEST FOR ft_calloc
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_calloc.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: ft_calloc(100, sizeof(int)) is not NULL,
**               all 400 bytes are 0
** - Edge cases: ft_calloc(0, 0) returns a freeable pointer,
**               ft_calloc(0, 10) returns a freeable pointer,
**               overflow: ft_calloc(SIZE_MAX, 2) -> NULL,
**               overflow: ft_calloc(SIZE_MAX / 2 + 1, 2) -> NULL,
**               overflow: ft_calloc(SIZE_MAX, SIZE_MAX) -> NULL
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Check that all n bytes are 0, not just the first ones
static int	all_zero(unsigned char *p, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (p[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int		*nums;
	char	*p;

	printf("--- happy path ---\n");
	nums = ft_calloc(100, sizeof(int));
	check(nums != NULL, "ft_calloc(100, sizeof(int)) is not NULL");
	check(nums && all_zero((unsigned char *)nums, 100 * sizeof(int)),
		"all 400 bytes are 0");
	free(nums);
	printf("--- edge cases ---\n");
	p = ft_calloc(0, 0);
	check(p != NULL,
		"ft_calloc(0, 0) returns a freeable pointer");
	free(p);
	p = ft_calloc(0, 10);
	check(p != NULL,
		"ft_calloc(0, 10) returns a freeable pointer");
	free(p);
	p = ft_calloc(SIZE_MAX, 2);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX, 2) -> NULL");
	free(p);
	p = ft_calloc(SIZE_MAX / 2 + 1, 2);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX / 2 + 1, 2) -> NULL");
	free(p);
	p = ft_calloc(SIZE_MAX, SIZE_MAX);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX, SIZE_MAX) -> NULL");
	free(p);
	printf("\nft_calloc: %d KO (also run it through valgrind)\n", g_ko);
	return (g_ko != 0);
}*/
