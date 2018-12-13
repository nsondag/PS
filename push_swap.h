/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:56:52 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/13 14:29:02 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WIN_HEIGHT 1005
# define WIN_WIDTH 1200

typedef struct	s_stack
{
	int *tab;
	int len;
}				t_stack;

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
}				t_visu;

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

t_stack			get_numbers(char **s);
t_stack			get_numbers2(char *s);
int				get_max(t_stack stack);
void			get_max2(t_stack stack, int *max, int *max2);
int				get_min(t_stack stack);
int				get_median(t_stack stack);
int				get_quartile(t_stack stack);

int				parser(t_stack *a, char **argv, int argc);
int				check_validity(char **s);
int				check_validity2(char *s);

void			left_shift(t_stack *stack);
void			right_shift(t_stack *stack);

int				ft_issorted(t_stack *a, int len_b);
int				ft_isrevsorted(t_stack *a, int len_b);

void			divide(t_stack *a, t_stack *b, int len, int pivot);
void			divide2(t_stack *a, t_stack *b, int len, int pivot);

void			quick_sort(t_stack *a, t_stack *b);
void			quick_sort2(t_stack *a, t_stack *b);
void			sort3(t_stack *a);
void			revsort3(t_stack *a);
void			sort5(t_stack *a, t_stack *b);
void			revsort5(t_stack *a, t_stack *b);

int				key_hook(int keycode, t_visu *v);
void			visualization(t_stack a, t_stack b, t_visu *v);

#endif
