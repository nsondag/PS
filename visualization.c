/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:15:59 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/07 17:37:30 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				key_hook(int keycode, t_visu *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
		exit(0);
	}
	return (0);
}

void		visualization(t_stack a, t_stack b)
{
	t_visu	v;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "PUSH_SWAP");
	mlx_key_hook(v.win_ptr, key_hook, &v);
	while (i < a.len)
	{
		j = a.tab[i];
		while (j > 0)
		{
			k = -1;
			while (++k < 9) 
				mlx_pixel_put(v.mlx_ptr, v.win_ptr,
						10 *j + k, i * 10 + k , 0xFF3300);
			j--;
		}
		i++;
	}
	i = 0;
	(void)b.tab[i];
	//{
	//	j = b.tab[i] + 1;
		//while (j > 0)
		//	mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, j--, 255);
	//	i++;
	//}
	mlx_loop(v.mlx_ptr);
}
