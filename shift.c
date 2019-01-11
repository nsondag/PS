/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:41:15 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/01 21:41:30 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	left_shift(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
}

void	right_shift(t_stack *stack)
{
	int count;

	count = stack->len - 1;
	while (count)
	{
		stack->tab[count] = stack->tab[count - 1];
		count--;
	}
}
