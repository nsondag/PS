/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:26:30 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/21 08:02:20 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack stack)
{
	int i;
	int j;
	int median;
	int count;

	count = 0;
	j = 0;
	while (count < stack.len / 2 || count > stack.len / 2)
	{
		count = 0;
		i = 0;
		median = stack.tab[j];
		while (i < stack.len)
		{
			if (stack.tab[i] < median)
				count++;
			i++;
		}
		j++;
	}
	return (median);
}

int	get_quartile(t_stack stack)
{
	int i;
	int j;
	int quartile;
	int count;

	count = 0;
	j = 0;
	while (count < stack.len / 4 || count > stack.len / 4)
	{
		count = 0;
		i = 0;
		quartile = stack.tab[j];
		while (i < stack.len)
		{
			if (stack.tab[i] <= quartile)
				count++;
			i++;
		}
		j++;
	}
	return (quartile);
}
