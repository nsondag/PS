/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/05 20:30:44 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				key_hook(int keycode, t_visu *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
		//exit(0);
	}
	return (0);
}

void		visualization(void)
{
	t_visu	v;

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "PUSH_SWAP");
	mlx_key_hook(v.win_ptr, key_hook, &v);
	mlx_loop(v.mlx_ptr);	
}

void		*fill_pixel(t_visu *visu, int x, int y)
{
	unsigned int position;

	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		position = (x + WIN_WIDTH * y) * 4;
	else
		return (0);
	visu->data[position] = 1;
	visu->data[position + 1] = 1;
	visu->data[position + 2] = 1;
	return (0);
}

//void		init()
//{

//}
