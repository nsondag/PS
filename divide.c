/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:08:46 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/18 23:09:10 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide(t_stack *a, t_stack *b, int len, int pivot)
{
	while (len > 1 && b->len)
	{
		if (b->tab[0] <= pivot)
			rot_b(b, 1);
		else
			push_a(a, b, 1);
		len--;
	}
}

void	divide2(t_stack *a, t_stack *b, int len, int pivot)
{
	while (len)
	{
		if (a->tab[0] > pivot)
			rot_a(a, 1);
		else if (a->tab[0] <= pivot)
		{
			push_b(a, b, 1);
			if (b->tab[0] == pivot)
				rot_b(b, 1);
		}
		len--;
	}
	revrot_b(b, 1);
}
