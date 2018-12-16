/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/16 03:17:14 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		next_pivot(t_stack *stack)
{
	int i;
	int pivot;
	int	found;
	int	max;

	max = get_max(*stack);
	pivot = 0;
	found = 0;
	while (pivot < stack->len && !found)
	{
		i = 0;
		while (i < stack->len && stack->tab[i] < max)
		{
			if ((i > pivot && stack->tab[i] > stack->tab[pivot]))
				break ;
			i++;
		}
		if (i == stack->len || stack->tab[i] == max)
		{
			pivot--;
			found = 1;
		}
		pivot++;
	}
	return (pivot);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	int median;
	int len;

	while (a->len > 20)
	{
		median = get_median(*a);
		len = a->len;
		divide2(a, b, len, median);
	}
	sort5(a, b);
}

void	quick_sort2(t_stack *a, t_stack *b)
{
	int len;
	int median;
	int	pivot;

	pivot = next_pivot(b);
	revsort5(a, b, (b->len + a->len) / 2);
	len = b->len;
	median = get_median(*b);
	while (b->len > len / 2 + 1)
	{
		if (b->tab[0] > median)
			push_a(a, b, 1);
		else
			rot_b(b, 1);
	}
	sort5(a, b);
	revsort5(a, b, 2);
	while (b->len)
		push_a(a, b, 1);
}
