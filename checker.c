/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:43:20 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/05 12:32:05 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_operation(t_stack *a, t_stack *b, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_a(a, 0);
	else if (ft_strcmp(operation, "sb") == 0)
		swap_b(b, 0);
	else if (ft_strcmp(operation, "ss") == 0)
		swap_ab(a, b, 0);
	else if (ft_strcmp(operation, "pa") == 0)
		push_a(a, b, 0);
	else if (ft_strcmp(operation, "pb") == 0)
		push_b(a, b, 0);
	else if (ft_strcmp(operation, "ra") == 0)
		rot_a(a, 0);
	else if (ft_strcmp(operation, "rb") == 0)
		rot_b(b, 0);
	else if (ft_strcmp(operation, "rr") == 0)
		rot_ab(a, b, 0);
	else if (ft_strcmp(operation, "rra") == 0)
		revrot_a(a, 0);
	else if (ft_strcmp(operation, "rrb") == 0)
		revrot_b(b, 0);
	else if (ft_strcmp(operation, "rrr") == 0)
		revrot_ab(a, b, 0);
	else
		return (0);
	return (1);
}

static int	checker(t_stack *a, t_stack *b)
{
	char		*operation;
	static int	count = 0;
	int		line;

	
	while ((line = get_next_line(0, &operation)) > 0)
	{
		if (!get_operation(a, b, operation))
		{
			free(operation);
			write(2, "Error\n", 6);
			return (0);
		}
		free(operation);
	}
	free(operation);
	if (ft_issorted(a, b->len, 0) && line <= 0)
		write(1, "OK\n", 3);
	else if (line <= 0)
		write(1, "KO\n", 3);
	return (count);
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		check;

	b.len = 0;
	check = parser(&a, argv, argc);
	if (!check)
		return (0);
	if (a.tab && check > 0)
	{
		if (!(b.tab = (int*)malloc(sizeof(int) * a.len)))
		{
			free(a.tab);
			return (0);
		}
		checker(&a, &b);
		free(b.tab);
		free(a.tab);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
