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
	if (ft_strncmp(arg, strategies[i].flag, ft_strlen(arg)) == 0)
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

	if (opt.start < argc && ft_strncmp(argv[opt.start], "--bench", ft_strlen("--bench")) == 0)
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
		else
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
	t_options opt;
	int		i;

	if (argc < 2)
	{
		ft_putendl_fd("Error: Faltan argumentos", 2);
		return (1);
	}

	// Parseamos las opciones con tu función
	opt = parse_options(argc, argv);

	// Imprimimos los resultados para verificar que funciona
	ft_putendl_fd("--- TEST DE PARSE_OPTIONS ---", 1);
	
	if (opt.bench)
		ft_putendl_fd("[✓] Modo BENCH activado", 1);
	else
		ft_putendl_fd("[✗] Modo BENCH desactivado", 1);

	// Mostramos qué estrategia se ha guardado (puedes adaptarlo según tus enums)
	ft_putstr_fd("Estrategia seleccionada (ID): ", 1);
	// Si strategy es un enum, se imprimirá como número entero
	// (SIMPLE = 0, MEDIUM = 1, COMPLEX = 2, ADAPTIVE = 3, por ejemplo)
	printf("%d\n", opt.strategy); 

	ft_putstr_fd("Índice de inicio de los números (opt.start): ", 1);
	printf("%d\n", opt.start);

	// Mostramos los números que quedan por ordenar a partir de opt.start
	ft_putendl_fd("Números a ordenar introducidos:", 1);
	i = opt.start;
	while (i < argc)
	{
		ft_putstr_fd("  -> ", 1);
		ft_putendl_fd(argv[i], 1);
		i++;
	}

	return (0);
}
