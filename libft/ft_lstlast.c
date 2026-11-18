/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:34:19 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:38:09 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
** TEST FOR ft_lstlast
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstlast.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: returns the last node (c)
** - Edge cases: NULL -> NULL, single node -> that node
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
	t_list	*last;

	list = new_node("a");
	list->next = new_node("b");
	last = new_node("c");
	list->next->next = last;
	printf("--- happy path ---\n");
	printf("     ft_lstlast(a -> b -> c)->content = \"%s\"\n",
		(char *)ft_lstlast(list)->content);
	check(ft_lstlast(list) == last, "returns the last node (c)");
	printf("--- edge cases ---\n");
	check(ft_lstlast(NULL) == NULL, "NULL -> NULL");
	check(ft_lstlast(last) == last, "single node -> that node");
	free_list(list);
	printf("\nft_lstlast: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
