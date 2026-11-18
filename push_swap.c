/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelkonj <imelkonj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:28:57 by imelkonj          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:17 by imelkonj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_has_space(char *ptr)
{
	int	i;

	i = 0;
	while(ptr[i])
	{
		--bench --medium "2 31 4" 
	}
			
}

static t_strategy get_strategy(char *arg, int *found)
{
    const t_strategy_map strategies[] = {
        {"--simple", SIMPLE},
        {"--medium", MEDIUM},
        {"--complex", COMPLEX},
        {"--adaptive", ADAPTIVE}
    };

	int i;
	
	i = 0;
	*found = 0;
    while (i < 4)
    {
	if (ft_strcmp(arg, strategies[i].flag) == 0)
	{
		*found = 1;
		return (strategies[i].strategy);
	}
	i++;
    }
    return (ADAPTIVE);
}

static	t_options parse_options(int argc, char **argv)
{
	t_options opt;
	int	found;

	opt.bench = 0;
	opt.strategy = ADAPTIVE;
	opt.start = 1;

	if (opt.start < argc && ft_strcmp(argv[opt.start], "--bench") == 0)
	{
		opt.bench = 1;
		opt.start++;
	}
	if (opt.start < argc)
	{
		opt.strategy = get_strategy(argv[opt.start], &found);
		if (found)
		{
			opt.strategy_selected = 1;
			opt.start++;
		}
		else if (argv[opt.start[0] == '-'])
		{
			ft_putstr_fd("Warning> Unkown option; ", 2);
			ft_putendl_fd(argv[opt.start], 2);
			ft_putendl_fd("Usiing default strategy: ADAPTIVE", 2);
		}
	}
	return (opt);
}

int	main(int argc, char **argv)
{
	if (!ft_is_valid_flag(*argv[1]))
		return (1);
	
	return (0);
}
