/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:21:14 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/04 23:54:05 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revsort3(t_stack *stack)
{
	int		min;

	if (stack->len == 3)
	{
		min = get_min(*stack);
		while (!ft_isrevsorted(stack, 0, stack->len))
		{
			if (stack->tab[0] == min)
				rot_b(stack, 1);
			else if (stack->tab[1] == min)
				revrot_b(stack, 1);
			else
				swap_b(stack, 1);
		}
	}
}

void	sort3(t_stack *stack)
{
	int		max;

	if (stack->len == 2)
	{
		if (stack->tab[0] > stack->tab[1])
			swap_a(stack, 1);
		else
			return ;
	}
	else if (stack->len == 3)
	{
		max = get_max(*stack);
		while (!ft_issorted(stack, 0, stack->len))
		{
			if (stack->tab[0] == max)
				rot_a(stack, 1);
			else if (stack->tab[1] == max)
				revrot_a(stack, 1);
			else
				swap_a(stack, 1);
		}
	}
}

void	sort5(t_stack *a, t_stack *b)
{
	int i;
	int i_min;
	int min;
	int count;

	count = 0;
	while (!ft_issorted(a, 0, 0) && a->len > 2)
	{
		i = 0;
		min = get_min(*a);
		while (a->tab[i] != min)
			i++;
		i_min = i;
		while (i_min <= a->len / 2 && a->tab[0] != min)
			rot_a(a, 1);
		while (i_min > a->len / 2 && a->tab[0] != min)
			revrot_a(a, 1);
		if (ft_issorted(a, b->len, 0))
			break ;
		push_b(a, b, 1);
		count++;
	}
	a->tab[0] > a->tab[1] ? swap_a(a, 1) : 0;
	while (count--)
		push_a(a, b, 1);
}

void	revsort5(t_stack *a, t_stack *b, int test)
{
	int max;
	int i_max;

	i_max = 0;
	if (b->len < test)
		test = b->len;
	while (!ft_isrevsorted(b, 0, test))
	{
		max = get_max(*b);
		while (b->tab[i_max] != max)
			i_max++;
		while (b->tab[0] != max && i_max < b->len / 2)
			rot_b(b, 1);
		push_a(a, b, 1);
		while (b->tab[0] != max && i_max >= b->len / 2)
			revrot_b(b, 1);
		push_a(a, b, 1);
	}
}
