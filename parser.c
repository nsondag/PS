/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:43:18 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/15 12:06:48 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	get_numbers(char **s)
{
	int		j;
	t_stack	stack;

	stack.len = 0;
	while (s[stack.len])
		stack.len++;
	if (!(stack.tab = (int*)malloc(sizeof(int) * stack.len)))
		stack.tab = NULL;
	stack.len = 0;
	while (stack.tab && s[stack.len])
	{
		j = 0;
		stack.tab[stack.len] = ft_atol(s[stack.len]);
		while (j < stack.len && stack.tab)
		{
			if (stack.tab[j++] == stack.tab[stack.len])
				stack.tab = NULL;
		}
		stack.len++;
	}
	return (stack);
}

static int		check_validity(char **s)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	while (s[i])
	{
		sign = 1;
		j = 0;
		if (s[i][j] == '-' || s[i][j] == '+')
			s[i][j++] == '-' ? sign = -1 : 0;
		if (!s[i][j])
			return (0);
		while (ft_isdigit(s[i][j]))
			j++;
		if (j > 11 || ft_atol(s[i]) > 2147483647 ||
						ft_atol(s[i]) < -2147483648 || s[i][j])
			return (0);
		i++;
	}
	return (1);
}

int				parser(t_stack *a, char **argv, int argc)
{
	int check;
	char **tab;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tab = ft_strsplit(argv[1], ' ');
		check = check_validity(tab);
		*a = get_numbers(tab);
		free(tab);
	}
	else
	{
		check = check_validity(&argv[1]);
		*a = get_numbers(&argv[1]);
	}
	if (check && a->tab)
		return (1);
	else
		return (-1);
}
