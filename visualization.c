/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/22 18:49:47 by nsondag          ###   ########.fr       */
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
		free(v->a.tab);
		free(v->b.tab);
		exit(0);
	}
	if (keycode == 49)
		v->stop = -v->stop;
	if (keycode == 1)
		v->slow = -v->slow;
	return (0);
}

void	visu_tab(t_visu v, t_stack a, int shift, int size)
{
	int		index[5];
	t_color	color;

	index[I] = -1;
	while (++index[I] < a.len)
	{
		color.i = 0xFF3300;
		index[J] = -1;
		if ((index[VALUE] = a.tab[index[I]]) < 0)
		{
			index[VALUE] = -index[VALUE];
			color.i = 0x33FF00;
		}
		while (++index[J] < index[VALUE])
		{
			index[K] = -1;
			while (++index[K] < size / 2)
			{
				index[L] = -1;
				while (++index[L] < size - 1)
					fill_pixel(&v, size / 2 * index[J] + index[K] + shift,
							index[I] * size + index[L], color);
			}
		}
	}
}

int		visualization(t_stack a, t_stack b, t_visu *v)
{
	int size;

	if (v->size < 101)
		size = 10;
	else
		size = 2;
	mlx_key_hook(v->win_ptr, key_hook, v);
	visu_tab(*v, a, 0, size);
	visu_tab(*v, b, WIN_WIDTH / 2, size);
	return (1);
}
