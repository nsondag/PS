/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/13 15:36:50 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*fill_pixel(t_visu *v, int x, int y, t_color color)
{
	unsigned int position;

	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		position = (x + WIN_WIDTH * y) * 4;
	else
		return (0);
	v->str[position] = color.tab[0];
	v->str[position + 1] = color.tab[1];
	v->str[position + 2] = color.tab[2];
	return (0);
}

int		key_hook(int keycode, t_visu *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
		exit(0);
	}
	if (keycode == 49)
		v->stop = -v->stop;
	if (keycode == 1)
		v->slow = -v->slow;
	return (0);
}

void	visu_tab(t_visu v, t_stack a, int shift)
{
	int		i;
	int		j;
	int		k;
	int		l;
	t_color	color;
	int		value;


	i = -1;
	while (++i < a.len)
	{
		color.i = 0xFF3300;
		j = -1;
		value = a.tab[i];
		//if (value == 76)
		//	color.i = 0xFFFFFF;
		if (value < 0)
		{
			value = -value;
			color.i = 0x33FF00;
		}
		while (++j < value)
		{
			k = -1;
			while (++k < 5)
			{
				l = -1;
				while (++l < 9)
					fill_pixel(&v, 5 * j + k + shift, i * 10 + l, color);
			}
		}
	}
}

void	visualization(t_stack a, t_stack b, t_visu *v)
{
	mlx_key_hook(v->win_ptr, key_hook, v);
	visu_tab(*v, a, 0);
	visu_tab(*v, b, WIN_WIDTH/2);
}
