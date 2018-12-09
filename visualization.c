/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/09 18:57:15 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		key_hook(int keycode, t_visu *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
		exit(0);
	}
	return (0);
}

void	visu_tab(t_visu v, t_stack a)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	while (i < a.len)
	{
		j = 0;
		while (j < a.tab[i])
		{
			k = -1;
			while (++k < 9)
			{
				l = -1;
				while (++l < 9)
					mlx_pixel_put(v.mlx_ptr, v.win_ptr,
							10 * j + k, i * 10 + l, 0xFF3300);
			}
			j++;
		}
		i++;
	}
}

void	visualization(t_stack a, t_stack b)
{
	t_visu	v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "PUSH_SWAP");
	mlx_key_hook(v.win_ptr, key_hook, &v);
	visu_tab(v, a);
	visu_tab(v, b);
	mlx_loop(v.mlx_ptr);
}
