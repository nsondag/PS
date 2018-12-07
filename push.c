/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:58:58 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/01 21:10:17 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	int first_src;

	if (src->len)
	{
		first_src = src->tab[0];
		left_shift(src);
		src->len -= 1;
		right_shift(dst);
		dst->tab[0] = first_src;
		dst->len += 1;
	}
}

void		push_a(t_stack *a, t_stack *b, int w)
{
	push(b, a);
	if (w)
		write(1, "pa\n", 3);
}

void		push_b(t_stack *a, t_stack *b, int w)
{
	push(a, b);
	if (w)
		write(1, "pb\n", 3);
}
