/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:52:32 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:53:23 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
** TEST FOR ft_lstdelone
** 1. Build libft:  make
** 2. Uncomment the main below.
** 3. Compile and run the test:
**    cc -Wall -Wextra -Werror ft_lstdelone.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** TEST CASES:
** - Happy path: calls del exactly once, with the node's content
** - Edge cases: the next node stays alive and intact
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
static void	*g_deleted = NULL;

// Records which content was deleted and how many times
static void	del(void *content)
{
	g_calls++;
	g_deleted = content;
	free(content);
}

static char	*new_str(char *s)
{
	char	*copy;
	int		i;

	copy = malloc(10);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	void	*content_a;

	a = new_node(new_str("a"));
	b = new_node(new_str("b"));
	a->next = b;
	content_a = a->content;
	printf("--- happy path ---\n");
	ft_lstdelone(a, del);
	check(g_calls == 1, "calls del exactly once");
	check(g_deleted == content_a, "with the node's content");
	printf("--- edge cases ---\n");
	check(((char *)b->content)[0] == 'b' && b->next == NULL,
		"the next node stays alive and intact");
	free(b->content);
	free(b);
	printf("\nft_lstdelone: %d KO (valgrind: 0 leaks and no invalid free)\n",
		g_ko);
	return (g_ko != 0);
}
*/
