/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:04:41 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/01 21:10:52 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot(t_stack *stack)
{
	int	first;

	if (stack->len)
	{
		first = stack->tab[0];
		left_shift(stack);
		stack->tab[stack->len - 1] = first;
	}
}

void		rot_a(t_stack *a, int w)
{
	rot(a);
	if (w)
		write(1, "ra\n", 3);
}

void		rot_b(t_stack *b, int w)
{
	rot(b);
	if (w)
		write(1, "rb\n", 3);
}

void		rot_ab(t_stack *a, t_stack *b, int w)
{
	rot(a);
	rot(b);
	if (w)
		write(1, "rr\n", 3);
}
