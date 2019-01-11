/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:41:15 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/11 14:23:13 by nsondag          ###   ########.fr       */
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

	count = stack->len;
	while (count > 0)
	{
		stack->tab[count] = stack->tab[count - 1];
		count--;
	}
}
