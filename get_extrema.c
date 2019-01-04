/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extrema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:29:28 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/04 23:59:06 by nsondag          ###   ########.fr       */
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
