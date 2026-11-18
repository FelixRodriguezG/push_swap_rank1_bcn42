/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelkonj <imelkonj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:28:33 by imelkonj          #+#    #+#             */
/*   Updated: 2026/11/18 18:04:02 by imelkonj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_strategy
{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
}   t_strategy;

typedef struct s_strategy_map
{
    char        *flag;
    t_strategy  strategy;
}   t_strategy_map;

typedef struct s_options
{
    int         bench;
    int	strategy_selected;
    t_strategy  strategy;
    int         start;
}   t_options;

int ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str);

#endif
