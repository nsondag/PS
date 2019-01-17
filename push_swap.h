/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:56:52 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/18 00:47:46 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>

# define WIN_HEIGHT 1005
# define WIN_WIDTH 1200

typedef struct	s_stack
{
	int *tab;
	int len;
}				t_stack;

typedef	union	u_color
{
	int				i;
	unsigned char	tab[4];
}				t_color;

typedef struct	s_visu
{
	int			bpp;
	int			sl;
	int			endian;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*data_ptr;
	char		*str;
	t_stack		a;
	t_stack		b;
	int			stop;
	int			slow;
	int			on;
	int			size;
}				t_visu;

int				parser(t_stack *a, char **argv, int argc, t_visu *v);

void			push_a(t_stack *a, t_stack *b, int write);
void			push_b(t_stack *a, t_stack *b, int write);
void			swap_a(t_stack *a, int write);
void			swap_b(t_stack *b, int write);
void			swap_ab(t_stack *a, t_stack *b, int write);
void			rot_a(t_stack *a, int write);
void			rot_b(t_stack *b, int write);
void			rot_ab(t_stack *a, t_stack *b, int write);
void			revrot_a(t_stack *a, int write);
void			revrot_b(t_stack *b, int write);
void			revrot_ab(t_stack *a, t_stack *b, int write);

void			left_shift(t_stack *stack);
void			right_shift(t_stack *stack);

int				get_max(t_stack stack);
int				get_min(t_stack stack);
int				get_median(t_stack stack, int len);
int				get_quartile(t_stack stack, int i, int len);
int				ft_issorted(t_stack *a, int len_b, int begin);

void			quick_sort_a(t_stack *a, t_stack *b, int end);
void			quick_sort(t_stack *a, t_stack *b);
void			sort3(t_stack *a);
void			sort5(t_stack *a, t_stack *b);

int				key_hook(int keycode, t_visu *v);
int				visualization(t_stack a, t_stack b, t_visu *v);

#endif
