/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 01:15:00 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/16 01:26:58 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
}

/*
** TEST FOR ft_lstclear
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstclear.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: sets *lst = NULL, calls del once per node (3)
** - Edge cases: empty list: does nothing
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

static int	g_calls = 0;

static void	del(void *content)
{
	g_calls++;
	free(content);
}

static void	*new_int(int value)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = value;
	return (p);
}

int	main(void)
{
	t_list	*list;

	list = new_node(new_int(1));
	list->next = new_node(new_int(2));
	list->next->next = new_node(new_int(3));
	printf("--- happy path ---\n");
	ft_lstclear(&list, del);
	check(list == NULL, "sets *lst = NULL");
	check(g_calls == 3, "calls del once per node (3)");
	printf("--- edge cases ---\n");
	g_calls = 0;
	list = NULL;
	ft_lstclear(&list, del);
	check(list == NULL && g_calls == 0, "empty list: does nothing");
	printf("\nft_lstclear: %d KO (valgrind: 0 leaks)\n", g_ko);
	return (g_ko != 0);
}
*/
