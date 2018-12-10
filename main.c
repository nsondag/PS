/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:43:20 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/10 13:47:49 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort(t_stack *a, t_stack *b, int visu, t_visu *v)
{

	visu ? visualization(*a, *b, v) : 0;
	if (!(b->tab = (int*)malloc(sizeof(int) * a->len)))
		return (0);
	if (!ft_issorted(a, b->len) && a->len > 20)
	{
		quick_sort(a, b);
		while (!ft_issorted(a, b->len))
			quick_sort2(a, b);
	}
	else if (a->len > 3)
	{
		while (!ft_issorted(a, b->len))
			sort5(a, b);
	}
	else if (a->len > 1)
	{
		while (!ft_issorted(a, b->len))
			sort3(a);
	}
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	visu ? visualization(*a, *b, v) : 0;
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		check;
	int		visu;
	t_visu	v;

	visu = 1; // to be done parsing for options
	b.len = 0;
	check = parser(&a, argv, argc);
	if (!check)
		return (0);
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "PUSH_SWAP");
	(a.tab && check > 0) ? sort(&a, &b, visu, &v) : write(2, "Error\n", 6);
	mlx_loop(v.mlx_ptr);
	free(a.tab);
	free(b.tab);
	return (0);
}
