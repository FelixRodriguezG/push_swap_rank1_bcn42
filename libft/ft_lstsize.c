/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:31:54 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:33:39 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count_nodes;

	count_nodes = 0;
	while (lst)
	{
		count_nodes++;
		lst = lst->next;
	}
	return (count_nodes);
}

/*
** TEST FOR ft_lstsize
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstsize.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: 3 nodes -> 3
** - Edge cases: NULL -> 0, 1 node -> 1, from the middle node -> 2
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Builds the node by hand to avoid depending on ft_lstnew
static t_list	*new_node(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	n->content = content;
	n->next = NULL;
	return (n);
}

static void	free_list(t_list *lst)
{
	t_list	*next_node;

	while (lst)
	{
		next_node = lst->next;
		free(lst);
		lst = next_node;
	}
}

int	main(void)
{
	t_list	*list;

	list = new_node("a");
	list->next = new_node("b");
	list->next->next = new_node("c");
	printf("--- happy path ---\n");
	printf("     ft_lstsize(a -> b -> c) = %u\n", ft_lstsize(list));
	check(ft_lstsize(list) == 3, "3 nodes -> 3");
	printf("--- edge cases ---\n");
	check(ft_lstsize(NULL) == 0, "NULL -> 0");
	check(ft_lstsize(list->next->next) == 1, "1 node -> 1");
	check(ft_lstsize(list->next) == 2, "from the middle node -> 2");
	free_list(list);
	printf("\nft_lstsize: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
