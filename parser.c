/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:43:18 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/22 22:43:17 by nsondag          ###   ########.fr       */
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
	if (!(stack.tab = (int*)malloc(sizeof(int) * (stack.len + 1))))
		stack.tab = NULL;
	stack.len = 0;
	while (stack.tab && s[stack.len])
	{
		j = 0;
		stack.tab[stack.len] = ft_atol(s[stack.len]);
		while (j < stack.len && stack.tab)
		{
			if (stack.tab[j++] == stack.tab[stack.len])
			{
				free(stack.tab);
				stack.tab = NULL;
			}
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

static int		parse_option(char *s, t_visu *v)
{
	s++;
	while (*s)
	{
		if (*s == 'v')
			v->on = 1;
		else
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		s++;
	}
	return (1);
}

static void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int				parser(t_stack *a, char **argv, int argc, t_visu *v)
{
	int		check;
	char	**tab;
	int		min_arg;

	min_arg = 1;
	while (++min_arg <= argc && argv[min_arg - 1][0] == '-' && v)
	{
		if (!ft_isdigit(argv[min_arg - 1][1]))
			check = parse_option(argv[min_arg - 1], v);
		else
			break ;
	}
	if (argc < min_arg || check < 0)
		return (0);
	if (argc == min_arg)
	{
		tab = ft_strsplit(argv[min_arg - 1], ' ');
		check = check_validity(tab);
		*a = get_numbers(tab);
		free_tab(tab);
		return ((check && a->tab) ? 1 : -1);
	}
	check = check_validity(&argv[min_arg - 1]);
	*a = get_numbers(&argv[min_arg - 1]);
	return ((check && a->tab) ? 1 : -1);
}
