/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/12 15:27:25 by nsondag          ###   ########.fr       */
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
	int pivot;
	int len;

	while (a->len > 25)
	{
		pivot = get_median(*a);
		len = a->len;
		divide2(a, b, len, pivot);
	}
	sort5(a, b);
	while (b->len > 3)
	{
		len = b->len;
		pivot = get_median(*b);
		divide(a, b, len, pivot);
	}
	revsort3(b);
	while (b->len)
		push_a(a, b, 1);
}

void	core(t_stack *a, t_stack *b, int len, int *first)
{
	int pivot;

	len = b->len;
	pivot = get_median(*b);
	while (len)
	{
		if (b->tab[0] < pivot && *first)
		{
			rot_ab(a, b, 1);
			*first = 0;
		}
		else if (b->tab[0] < pivot)
			rot_b(b, 1);
		else
		{
			if (*first)
				rot_a(a, 1);
			push_a(a, b, 1);
			*first = 0;
		}
		len--;
	}
}

void	quick_sort2(t_stack *a, t_stack *b)
{
	int len;
	int first;

	first = 0;
	len = next_pivot(a);
	if (!len)
		rot_a(a, 1);
	else if (a->tab[0] > a->tab[1])
		swap_a(a, 1);
	else
	{
		while (len--)
			push_b(a, b, 1);
		first = 1;
		if (b->len <= 25)
			rot_a(a, 1);
		while (b->len > 25)
			core(a, b, len, &first);
	}
	revsort5(a, b);
	while (b->len)
		push_a(a, b, 1);
}
