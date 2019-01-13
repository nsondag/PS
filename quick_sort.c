/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/13 21:31:53 by nsondag          ###   ########.fr       */
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

void		quick_sort(t_stack *a, t_stack *b, int end)
{
	int median;
	int len;
	int	max;

	if (end == -1)
		len = a->len;
	else
		len = end;
	median = get_median(*a, len);
	while (len)
	{
		if (a->tab[0] <= median)
			push_b(a, b, 1);
		else
			rot_a(a, 1);
		b->tab[0] == median ? rot_b(b, 1) : 0;
		len--;
	}
	max = get_max(*a);
	while (a->tab[a->len - 1] != max && end != -1)
		revrot_a(a, 1);
	if (b->len && b->tab[b->len - 1] == median)
		revrot_b(b, 1);
}

static void	quick_sort_b(t_stack *a, t_stack *b)
{
	int median;
	int len;

	len = b->len;
	median = get_median(*b, len);
	while (len)
	{
		if (b->tab[0] >= median)
			push_a(a, b, 1);
		else
			rot_b(b, 1);
		a->tab[0] == median ? rot_a(a, 1) : 0;
		len--;
	}
	if (a->len && a->tab[a->len - 1] == median)
		revrot_a(a, 1);
}

void		quick_sort2(t_stack *a, t_stack *b, int end)
{
	int max;
	int pivot;

	(a->tab[0] > a->tab[1] && ft_issorted(a, 0, 1)) ? swap_a(a, 1) : 0;
	max = get_max(*b);
	(b->tab[1] == max && b->len > 0) ? swap_b(b, 1) : 0;
	(b->tab[0] == max && ft_issorted(a, 0, 0)) ? push_a(a, b, 1) : 0;
	if (ft_issorted(a, 0, 0) && b->len > 0)
	{
		pivot = next_pivot(b);
		if (pivot == b->tab[b->len - 1] && b->len > 1)
			quick_sort_b(a, b);
		else
		{
			while (b->tab[0] != pivot && b->len > 0)
				push_a(a, b, 1);
			push_a(a, b, 1);
		}
		return ;
	}
	end = 0;
	while (!ft_issorted(a, 0, end))
		end++;
	end < 25 ? sort5(a, b) : 0;
	(!ft_issorted(a, 0, 0)) ? quick_sort(a, b, end + 1) : 0;
}
