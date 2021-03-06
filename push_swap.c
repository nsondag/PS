/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:43:20 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/22 22:42:10 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort(t_stack *a, t_stack *b)
{
	if (!ft_issorted(a, b->len, 0) && a->len > 20)
	{
		while (a->len > 20 && !ft_issorted(a, 0, 0))
			quick_sort_a(a, b, -1);
		sort5(a, b);
		while (!ft_issorted(a, b->len, 0))
			quick_sort(a, b);
	}
	else if (a->len > 3)
	{
		while (!ft_issorted(a, b->len, 0))
			sort5(a, b);
	}
	else if (a->len > 1)
	{
		while (!ft_issorted(a, b->len, 0))
			sort3(a);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		check;

	b.len = 0;
	check = parser(&a, argv, argc, NULL);
	if (!check)
		return (0);
	if (!(b.tab = (int*)malloc(sizeof(int) * (a.len + 1))))
	{
		free(a.tab);
		return (0);
	}
	(a.tab && check > 0) ? sort(&a, &b) : write(2, "Error\n", 6);
	free(a.tab);
	free(b.tab);
	return (0);
}
