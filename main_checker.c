/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:43:20 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/11 21:23:54 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_operation(t_stack *a, t_stack *b, char *operation, t_visu *v)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_a(a, 0);
	else if (ft_strcmp(operation, "sb") == 0)
		swap_b(b, 0);
	else if (ft_strcmp(operation, "ss") == 0)
		swap_ab(a, b, 0);
	else if (ft_strcmp(operation, "pa") == 0)
		push_a(a, b, 0);
	else if (ft_strcmp(operation, "pb") == 0)
		push_b(a, b, 0);
	else if (ft_strcmp(operation, "ra") == 0)
		rot_a(a, 0);
	else if (ft_strcmp(operation, "rb") == 0)
		rot_b(b, 0);
	else if (ft_strcmp(operation, "rr") == 0)
		rot_ab(a, b, 0);
	else if (ft_strcmp(operation, "rra") == 0)
		revrot_a(a, 0);
	else if (ft_strcmp(operation, "rrb") == 0)
		revrot_b(b, 0);
	else if (ft_strcmp(operation, "rrr") == 0)
		revrot_ab(a, b, 0);
	else
		return (0);
	visualization(*a, *b, v);
	return (1);
}

int		checker(t_stack *a, t_stack *b, t_visu *v)
{
	char	*operation;
	int		line;

	if ((line = get_next_line(0, &operation)) > 0)
	{
		if (!get_operation(a, b, operation, v))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (ft_issorted(a, b->len) && line <= 0)
		write(1, "OK\n", 3);
	else if (line <= 0)
		write(1, "KO\n", 3);
	return (0);
}

int				loop_hook(t_visu *v)
{
	//usleep(100000);
	checker(&v->a, &v->b, v);
	return (0);
}

int				main(int argc, char **argv)
{
	//t_stack	a;
	//t_stack	b;
	int		check;
	t_visu	v;

	v.b.len = 0;
	check = parser(&v.a, argv, argc);
	if (!check)
		return (0);
	if (v.a.tab && check > 0)
	{
		if (!(v.b.tab = (int*)malloc(sizeof(int) * v.a.len)))
		{
			free(v.a.tab);
			return (0);
		}
		v.mlx_ptr = mlx_init();
		v.img_ptr = mlx_new_image(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		v.str = mlx_get_data_addr(v.img_ptr, &v.bpp, &v.sl, &v.endian);
		//visualization(a, b, &v);
		//checker(&a, &b, &v);
		//free(a.tab);
		//free(b.tab);
		v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "PUSH_SWAP");
		mlx_loop_hook(v.mlx_ptr, loop_hook, &v);
		mlx_loop(v.mlx_ptr);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
