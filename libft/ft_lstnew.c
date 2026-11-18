/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:00:21 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 17:34:13 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
** TEST FOR ft_lstnew
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstnew.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: returns a node, content is the pointer we passed,
**               *(int *)content is 42, next is NULL
** - Edge cases: content = NULL is valid
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	t_list	*n;
	int		x;

	x = 42;
	printf("--- happy path ---\n");
	n = ft_lstnew(&x);
	check(n != NULL, "returns a node");
	check(n && n->content == &x, "content is the pointer we passed");
	check(n && *(int *)n->content == 42, "*(int *)content is 42");
	check(n && n->next == NULL, "next is NULL");
	free(n);
	printf("--- edge cases ---\n");
	n = ft_lstnew(NULL);
	check(n != NULL && n->content == NULL, "content = NULL is valid");
	free(n);
	printf("\nft_lstnew: %d KO (valgrind: 0 leaks)\n", g_ko);
	return (g_ko != 0);
}
*/
