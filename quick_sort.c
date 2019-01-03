/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:19:58 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/03 12:54:00 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack *a, t_stack *b, int end)
{
	int median;
	int len;
	int min;
	int	max;

	len = end;
	//printf("end %d\n", end);
	median = get_median(*a, end);
	//printf("median %d\n", median);
	min = get_min(*a); // not sure that's usefull
	while (len && min <= median)
	{
		min = get_min(*a); // not sure that's usefull
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
	int min;

	//if (b->len < 1)
	//	exit(0);
	i = 0;
	(a->tab[0] > a->tab[1] && ft_issorted(a, 0, 1)) ? swap_a(a, 1) : 0;
	max = get_max(*b);
	if (b->tab[0] == max && b->len > 0 && ft_issorted(a, b->len, a->len))
		push_a(a, b, 1);
	if (ft_issorted(a, 0, 0) && b->len > 0)
	{
		max = get_max(*b);
		min = max;
		while (b->tab[0] != max && b->len > 0)
		{
			//if (b->tab[0] < min)
			//	min = b->tab[0];
			push_a(a, b, 1);
		}
		push_a(a, b, 1);
	}
	else
	{
		end = 0;
		while (!ft_issorted(a, 0, end))
			end++;
		if (!ft_issorted(a, 0, 0))
			quick_sort(a, b, end);
	}
}
