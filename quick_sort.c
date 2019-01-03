/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/03 16:06:56 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		next_pivot(t_stack *stack)
{
	int i;
	int pivot;
	int	found;
	//int	max;

	//max = get_max(*stack);
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

void	quick_sort(t_stack *a, t_stack *b, int end)
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
	while (a->tab[a->len - 1] != max)
		revrot_a(a, 1);
	if (b->len && b->tab[b->len - 1] == median)
		revrot_b(b, 1);
}

void	quick_sort2(t_stack *a, t_stack *b, int end)
{
	int max;
	int i;
	int pivot;

	i = 0;
	(a->tab[0] > a->tab[1] && ft_issorted(a, 0, 1)) ? swap_a(a, 1) : 0;
	max = get_max(*b);
	if (b->tab[0] == max && b->len > 0 && ft_issorted(a, b->len, a->len))
		push_a(a, b, 1);
	if (ft_issorted(a, 0, 0) && b->len > 0)
	{
		max = get_max(*b);
		pivot = next_pivot(b);
		//printf("%d\n", pivot);
		while (b->tab[0] != pivot && b->len > 0)
			push_a(a, b, 1);
		push_a(a, b, 1);
		//min = get_min(*a);
		//max = get_max(*b);
		//while (max < min)
		//{
		//	push_a(a, b, 1);
		//	min = get_min(*a);
		//	max = get_max(*b);
		//}

	}
	else
	{
		end = 0;
		while (!ft_issorted(a, 0, end))
			end++;
		if (!ft_issorted(a, 0, 0))
			quick_sort(a, b, end + 1);
	}
}
