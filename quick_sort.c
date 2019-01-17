/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/18 00:59:02 by nsondag          ###   ########.fr       */
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
	int	i;
	int	quartile;

	if (end == -1)
		len = a->len;
	else
		len = end;
	median = get_median(*a, len);
	quartile = get_quartile(*a, 3, len);
	while (len)
	{
		if (a->tab[0] <= median)
			push_b(a, b, 1);
		else
			rot_a(a, 1);
		(b->tab[0] == median && len > 1) ? rot_b(b, 1) : 0;
		len--;
	}
	i = 1;
	max = get_max(*a);
	while (a->len - i > 0 && a->tab[a->len - i] != max && end != -1)
		i++;
	while (a->tab[a->len - i] <= quartile && end != -1)
		i--;
	while (a->tab[a->len - 1] != max && end != -1)
		revrot_a(a, 1);
	if (b->len && b->tab[b->len - 1] == median)
		revrot_b(b, 1);
}

static void	quick_sort_b(t_stack *a, t_stack *b, int end)
{
	int median;
	int len;
	int	min;
	int	i;
	int	quartile;

	i = 1;
	min = b->tab[b->len - 1];
	if (end == -1)
		len = b->len;
	else
		len = end;
	median = get_median(*b, len);
	quartile = get_quartile(*a, 1, len);
	while (len)
	{
		if (b->tab[0] >= median)
			push_a(a, b, 1);
		else
			rot_b(b, 1);
		(a->tab[0] == median && len > 1) ? rot_a(a, 1) : 0;
		len--;
	}
	while (b->len - i > 0 && b->tab[b->len - i] != min && end != -1)
		i++;
	while (b->len - i > 0 && b->tab[b->len - i] >= quartile && end != -1)
		i++;
	while (b->len - i > 0 && b->tab[b->len - 1] != min && end != -1)
		revrot_b(b, 1);
	if (a->len && a->tab[a->len - 1] == median)
		revrot_a(a, 1);
}

void		quick_sort(t_stack *a, t_stack *b)
{
	int max;
	int pivot;
	int	i;

	i = 0;
	(a->tab[0] > a->tab[1] && ft_issorted(a, 0, 1)) ? swap_a(a, 1) : 0;
	max = get_max(*b);
	(b->tab[1] == max && b->len > 0) ? swap_b(b, 1) : 0;
	(b->tab[0] == max && ft_issorted(a, 0, 0)) ? push_a(a, b, 1) : 0;
	if (ft_issorted(a, 0, 0) && b->len > 0)
	{
		pivot = next_pivot(b);
		if (pivot == b->tab[b->len - 1] && b->len > 2)
			quick_sort_b(a, b, -1);
		else
		{
			while (b->tab[i] != pivot && b->len > 1)
				i++;
			!i ? push_a(a, b, 1) : quick_sort_b(a, b, i);
		}
		return ;
	}
	i = 0;
	while (!ft_issorted(a, 0, i))
		i++;
	if (!ft_issorted(a, 0, 0))
		(i < 20) ? sort5(a, b) : quick_sort_a(a, b, i + 1);
}
