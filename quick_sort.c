/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/22 18:30:03 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_pivot(t_stack *stack)
{
	int i;
	int pivot;
	int	found;

	pivot = 0;
	found = 0;
	while (pivot < stack->len && !found)
	{
		i = 0;
		while (i < stack->len)
		{
			if (i < pivot && stack->tab[i] < stack->tab[pivot])
				break ;
			if (i > pivot && stack->tab[i] > stack->tab[pivot])
				break ;
			i++;
		}
		if (i == stack->len)
		{
			pivot--;
			found = 1;
		}
		pivot++;
	}
	return (stack->tab[pivot]);
}

void		quick_sort_a(t_stack *a, t_stack *b, int end)
{
	int i[4];

	ft_bzero(i, 4);
	i[MEDIAN] = get_median(*a, end);
	while ((i[MIN] = get_min(*a)) <= i[MEDIAN])
	{
		(a->tab[0] <= i[MEDIAN]) ? push_b(a, b, 1) : rot_a(a, 1);
		(b->tab[0] == i[MEDIAN]) ? rot_b(b, 1) : 0;
	}
	i[MAX] = get_max(*a);
	while (a->tab[a->len - 1] != i[MAX] && end != -1 && i[COUNT]++ >= 0)
		revrot_a(a, 0);
	while (!ft_issorted(a, 0, i[S]))
		i[S]++;
	while (i[COUNT]-- > 0)
		rot_a(a, 0);
	if (i[S] >= 20)
	{
		while (a->tab[a->len - 2] != i[MAX] && end != -1)
			revrot_a(a, 1);
		b->len && b->tab[b->len - 1] == i[MEDIAN] ? revrot_ab(a, b, 1) : 0;
		return ;
	}
	(b->len && b->tab[b->len - 1] == i[MEDIAN]) ? revrot_b(b, 1) : 0;
	sort5(a, b);
}

static void	quick_sort_b(t_stack *a, t_stack *b, int end)
{
	int median;
	int	min;
	int max;

	min = b->tab[b->len - 1];
	median = get_median(*b, end);
	max = get_max(*b);
	while (median <= max)
	{
		max = get_max(*b);
		b->tab[0] >= median ? push_a(a, b, 1) : rot_b(b, 1);
		(a->tab[0] == median) ? rot_a(a, 1) : 0;
	}
	while (b->len - 2 >= 0 && b->tab[b->len - 2] != min && end != -1)
		revrot_b(b, 1);
	if (a->len - 1 >= 0 && a->tab[a->len - 1] == median)
		revrot_ab(a, b, 1);
	else if (b->len - 1 >= 0 && b->tab[b->len - 1] != min && end != -1)
		revrot_b(b, 1);
}

void		quick_sort(t_stack *a, t_stack *b)
{
	int max;
	int	i;

	i = 0;
	(a->tab[0] > a->tab[1] && ft_issorted(a, 0, 1)) ? swap_a(a, 1) : 0;
	max = get_max(*b);
	(b->tab[1] == max && b->len > 0) ? swap_b(b, 1) : 0;
	(b->tab[0] == max && ft_issorted(a, 0, 0)) ? push_a(a, b, 1) : 0;
	if (ft_issorted(a, 0, 0) && b->len > 0)
	{
		max = next_pivot(b);
		if (b->len > 2 && max == b->tab[b->len - 1])
			quick_sort_b(a, b, -1);
		else
		{
			while (b->tab[i] != max && b->len > 1)
				i++;
			i < 20 ? revsort5(a, b, i) : quick_sort_b(a, b, i);
		}
		return ;
	}
	i = 0;
	while (!ft_issorted(a, 0, i))
		i++;
	(!ft_issorted(a, 0, 0)) ? quick_sort_a(a, b, i + 1) : 0;
}
