/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:29:28 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/05 12:17:15 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack stack)
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

int	get_min(t_stack stack)
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

int	get_median(t_stack stack, int len)
{
	int i;
	int j;
	int median;
	int count;

	count = 0;
	j = 0;
	while (count < len / 2 || count > len / 2)
	{
		count = 0;
		i = 0;
		median = stack.tab[j];
		while (i < len)
		{
			if (stack.tab[i] < median)
				count++;
			i++;
		}
		j++;
	}
	return (median);
}
