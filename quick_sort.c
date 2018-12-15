/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/15 19:46:29 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		next_pivot(t_stack *stack)
{
	int i;
	int pivot;
	int	found;
	int	min;

	min = get_min(*stack);
	pivot = 0;
	found = 0;
	while (pivot < stack->len && !found)
	{
		i = 0;
		while (i < stack->len && stack->tab[i] > min)
		{
			if ((i > pivot && stack->tab[i] < stack->tab[pivot]))
				break ;
			i++;
		}
		if (i == stack->len || stack->tab[i] == min)
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

	while (a->len > 25)
	{
		median = get_median(*a);
		len = a->len;
		divide2(a, b, len, median);
	}
	sort5(a, b);
}

void	quick_sort2(t_stack *a, t_stack *b)
{
	int sorted;
	int len;
	int median;

	revsort5(a, b, 50);
	sorted = a->len - 1;
	len = b->len;
	median = get_median(*b);
	while (b->len > len / 2 + 1)
	{
		if (b->tab[0] > median)
			push_a(a, b, 1);
		else
			rot_b(b, 1);
	}
	while (a->len > sorted)
		push_b(a, b, 1);
	revsort5(a, b, 2);
	//median = get_median(*b);
	//len = b->len;
	while (b->len)
		push_a(a, b, 1);
}
