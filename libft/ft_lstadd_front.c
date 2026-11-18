/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:34:58 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 17:44:49 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
** TEST FOR ft_lstadd_front
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstadd_front.c -L. -lft && ./a.out
**
** TEST CASES:
** - Happy path: the new node is the head, the old first node comes after it,
**               the list still ends in NULL
** - Edge cases: empty list: the new node becomes the head,
**               and its next is still NULL
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

	a = new_node("a");
	b = new_node("b");
	printf("--- edge cases ---\n");
	list = NULL;
	ft_lstadd_front(&list, a);
	check(list == a, "empty list: the new node becomes the head");
	check(a->next == NULL, "and its next is still NULL");
	printf("--- happy path ---\n");
	ft_lstadd_front(&list, b);
	check(list == b, "the new node is the head");
	check(b->next == a, "the old first node comes after it");
	check(a->next == NULL, "the list still ends in NULL");
	free_list(list);
	printf("\nft_lstadd_front: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
