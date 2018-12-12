/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/12 15:03:48 by nsondag          ###   ########.fr       */
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
	if (keycode == 49)
		v->stop = -v->stop;
	return (0);
}

void	visu_tab(t_visu v, t_stack a, int shift)
{
	int i;
	int j;
	int k;
	int l;
	int color;
	int value;


	i = -1;
	while (++i < a.len)
	{
		color = 0xFF3300;
		j = -1;
		value = a.tab[i];
		if (value < 0)
		{
			value = -value;
			color = 0x33FF00;
		}
		while (++j < value)
		{
			k = -1;
			while (++k < 5)
			{
				l = -1;
				while (++l < 9)
					mlx_pixel_put(v.mlx_ptr, v.win_ptr,
							5 * j + k + shift, i * 10 + l, color);
			}
		}
	}
}

void	visualization(t_stack a, t_stack b, t_visu *v)
{
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
	mlx_key_hook(v->win_ptr, key_hook, v);
	visu_tab(*v, a, 0);
	visu_tab(*v, b, WIN_WIDTH/2);
}
