/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:43:18 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/05 12:29:41 by nsondag          ###   ########.fr       */
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
		stack.tab[stack.len] = ft_atoi(s[stack.len]);
		while (j < stack.len && stack.tab)
		{
			if (stack.tab[j++] == stack.tab[stack.len])
				stack.tab = NULL;
		}
		stack.len++;
	}
	return (stack);
}

static t_stack	get_numbers2(char *s)
{
	int		k;
	t_stack	stack;
	char	**tab;

	stack.len = 0;
	tab = ft_strsplit(s, ' ');
	while (tab[stack.len++])
		;
	if (!(stack.tab = (int*)malloc(sizeof(int) * stack.len)))
		stack.tab = NULL;
	stack.len = 0;
	while (stack.tab && tab[stack.len])
	{
		k = 0;
		stack.tab[stack.len] = ft_atoi(tab[stack.len]);
		while (k < stack.len && stack.tab)
		{
			if (stack.tab[k] == stack.tab[stack.len])
				stack.tab = NULL;
			k++;
		}
		stack.len++;
	}
	free(tab);
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
		if (((j > 11 || ft_atoi(s[i]) * sign < 0) &&
					!(ft_atoi(s[i]) == -2147483648)) || s[i][j])
			return (0);
		i++;
	}
	return (1);
}

static int		check_validity2(char *s)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	while (s[i])
	{
		sign = 1;
		j = 0;
		if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
			sign = s[i++] == '-' ? -1 : 1;
		while (ft_isdigit(s[i]) && s[i])
		{
			i++;
			j++;
		}
		if (s[i] && s[i] != ' ')
			return (0);
		if (((j > 11 || ft_atoi(&s[i - j - 1]) * sign < 0) &&
					!(ft_atoi(&s[i - j]) == -2147483648)))
			return (0);
		while (s[i] == ' ')
			i++;
	}
	return (1);
}

int				parser(t_stack *a, char **argv, int argc)
{
	int check;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		check = check_validity2(argv[1]);
		*a = get_numbers2(argv[1]);
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
