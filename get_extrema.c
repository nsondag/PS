/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extrema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:29:28 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/04 20:19:58 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max(t_stack stack)
{
	int i;
	int max;

	i = 0;
	max = -2147483648;
	while (i < stack.len)
	{
		if (stack.tab[i] > max)
			max = stack.tab[i];
		i++;
	}
	return (max);
}

void	get_max2(t_stack stack, int *max, int *max2)
{
	int i;
	int i_max;
	int i_max2;

	i = 0;
	*max = stack.tab[0];
	i_max = 0;
	*max2 = stack.tab[0];
	i_max2 = 0;
	while (i < stack.len)
	{
		if (stack.tab[i] >= *max)
		{
			*max = stack.tab[i];
			i_max = i;
		}
		if (stack.tab[i] > *max2 && stack.tab[i] <= *max)
		{
			*max2 = stack.tab[i];
			i_max2 = i;
		}
		i++;
	}
}

int		get_min(t_stack stack)
{
	int i;
	int min;

	i = 0;
	min = 2147483647;
	while (i < stack.len)
	{
		if (stack.tab[i] < min)
			min = stack.tab[i];
		i++;
	}
	return (min);
}
