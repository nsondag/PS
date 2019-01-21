/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:43:20 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/21 09:29:02 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_operation(t_stack *a, t_stack *b, char *operation, t_visu *v)
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
	return (v->on ? visualization(*a, *b, v) : 1);
}

static int	checker(t_stack *a, t_stack *b, t_visu *v)
{
	char		*operation;
	int			line;
	static int	count = 0;

	if (v->on)
	{
		if ((line = get_next_line(0, &operation)) > 0)
		{
			if (!get_operation(a, b, operation, v))
			{
				free(operation);
				write(2, "Error\n", 6);
				return (0);
			}
			free(operation);
			count++;
		}
	}
	else
	{
		while ((line = get_next_line(0, &operation)) > 0)
		{
			if (!get_operation(a, b, operation, v))
			{
				free(operation);
				write(2, "Error\n", 6);
				return (0);
			}
			free(operation);
		}
		free(operation);
	}
	line == 0 ? v->stop = 0 : 0;
	if (ft_issorted(a, b->len, 0) && !v->stop)
		write(1, "OK\n", 3);
	else if (!v->stop)
		write(1, "KO\n", 3);
	return (count);
}

int			loop_hook(t_visu *v)
{
	int	count;

	if (v->stop < 0)
	{
		if (v->slow == 1)
			usleep(50000);
		v->img_ptr = mlx_new_image(v->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		v->str = mlx_get_data_addr(v->img_ptr, &v->bpp, &v->sl, &v->endian);
		if (v->stop == -2)
		{
			v->stop = 1;
			visualization(v->a, v->b, v);
			count = 0;
		}
		else
			count = checker(&v->a, &v->b, v);
		if (ft_issorted(&v->a, v->b.len, 0))
			v->stop = 0;
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
		mlx_destroy_image(v->mlx_ptr, v->img_ptr);
		mlx_string_put(v->mlx_ptr, v->win_ptr, 1000, 50, 0xFFFFFF, ft_itoa(count));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_visu	v;
	int		check;

	v.stop = -2;
	v.slow = -1;
	v.b.len = 0;
	check = parser(&v.a, argv, argc, &v);
	if (v.a.tab && check > 0)
	{
		v.size = v.a.len;
		if (!(v.b.tab = (int*)malloc(sizeof(int) * v.a.len)))
		{
			free(v.a.tab);
			return (0);
		}
		if (v.on)
		{
			v.mlx_ptr = mlx_init();
			v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
					"PUSH_SWAP");
			mlx_key_hook(v.win_ptr, key_hook, &v);
			mlx_loop_hook(v.mlx_ptr, loop_hook, &v);
			mlx_loop(v.mlx_ptr);
		}
		checker(&v.a, &v.b, &v);
		free(v.b.tab);
		free(v.a.tab);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
