/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/21 08:04:22 by nsondag          ###   ########.fr       */
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
	int median;
	int len;
	int	max;
	int min;
	int	i = 0;
	int	count = 0;

	if (end == -1)
		len = a->len;
	else
		len = end;
	median = get_median(*a, len);
	min = get_min(*a);
	while (len && median >= min)
	{
		if (a->tab[0] <= median)
			push_b(a, b, 1);
		else
			rot_a(a, 1);
		(b->tab[0] == median && len > 1) ? rot_b(b, 1) : 0;
		len--;
		min = get_min(*a);
	}
	max = get_max(*a);
	i = 0;
	while (a->tab[a->len - 1] != max && end != -1)
	{
		revrot_a(a, 0);
		count++;
	}
	while (!ft_issorted(a, 0, i))
		i++;
	while (count-- > 0)
		rot_a(a, 0);
	if (i >= 20)
	{
		while (a->tab[a->len - 2] != max && end != -1)
			revrot_a(a, 1);
		if (b->len && b->tab[b->len - 1] == median)
			revrot_ab(a, b, 1);
		else if (a->tab[a->len - 1] != max && end != -1)
			revrot_a(a, 1);
	}
	else
	{
		if (b->len && b->tab[b->len - 1] == median)
			revrot_b(b, 1);
		sort5(a, b);
	}
}

static void	quick_sort_b(t_stack *a, t_stack *b, int end)
{
	int median;
	int len;
	int	min;
	int max;

	min = b->tab[b->len - 1];
	len = (end == -1) ? b->len : end;
	median = get_median(*b, len);
	max = get_max(*b);
	while (len && median <= max)
	{
		max = get_max(*b);
		if (b->tab[0] >= median)
			push_a(a, b, 1);
		else
			rot_b(b, 1);
		(a->tab[0] == median && len > 1) ? rot_a(a, 1) : 0;
		len--;
	}
	while (b->tab[b->len - 2] != min && end != -1)
		revrot_b(b, 1);
	if (a->len && a->tab[a->len - 1] == median)
		revrot_ab(a, b, 1);
	else if (b->tab[b->len - 1] != min && end != -1)
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
		if (max == b->tab[b->len - 1] && b->len > 2)
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
