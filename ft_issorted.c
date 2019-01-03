/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 05:48:32 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/02 19:38:54 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isrevsorted(t_stack *a, int len_b)
{
	int i;

	i = 0;
	if (len_b)
		return (0);
	while (i < a->len - 1)
	{
		if (a->tab[i] < a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_issorted(t_stack *a, int len_b, int begin)
{
	int i;

	i = begin;
	if (len_b)
		return (0);
	while (i < a->len - 1)
	{
		if (a->tab[i] > a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
