/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:58:58 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/01 22:04:37 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_a(t_stack *a, int w)
{
	if (a->len > 1)
	{
		ft_swap(&a->tab[0], &a->tab[1]);
		if (w)
			write(1, "sa\n", 3);
	}
}

void		swap_b(t_stack *b, int w)
{
	if (b->len > 1)
	{
		ft_swap(&b->tab[0], &b->tab[1]);
		if (w)
			write(1, "sb\n", 3);
	}
}

void		swap_ab(t_stack *a, t_stack *b, int w)
{
	if (a->len > 1)
	{
		ft_swap(&a->tab[0], &a->tab[1]);
		if (b->len > 1)
			ft_swap(&b->tab[0], &b->tab[1]);
		if (w)
			write(1, "ss\n", 3);
	}
}
