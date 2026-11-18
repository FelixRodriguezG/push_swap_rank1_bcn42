/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:42:52 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:43:37 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
** TEST FOR ft_lstadd_back
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstadd_back.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: appends the node at the end (a -> b), the list ends in NULL
** - Edge cases: appending a whole chain (a -> b -> c -> d),
**               the head does not change
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Build the node by hand to avoid depending on ft_lstnew
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
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = new_node("a");
	b = new_node("b");
	c = new_node("c");
	c->next = new_node("d");
	printf("--- edge cases ---\n");
	list = NULL;
	ft_lstadd_back(&list, a);
	check(list == a, "empty list: *lst becomes the new node");
	printf("--- happy path ---\n");
	ft_lstadd_back(&list, b);
	check(a->next == b, "appends the node at the end (a -> b)");
	check(b->next == NULL, "the list ends in NULL");
	printf("--- edge cases ---\n");
	ft_lstadd_back(&list, c);
	check(b->next == c && c->next && c->next->next == NULL,
		"appending a whole chain (a -> b -> c -> d)");
	check(list == a, "the head does not change");
	free_list(list);
	printf("\nft_lstadd_back: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
