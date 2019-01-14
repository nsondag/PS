/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:56:52 by nsondag           #+#    #+#             */
/*   Updated: 2019/01/14 15:40:40 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_stack
{
	int *tab;
	int len;
}				t_stack;

int				parser(t_stack *a, char **argv, int argc);

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
int				ft_issorted(t_stack *a, int len_b, int begin);

void			quick_sort(t_stack *a, t_stack *b, int end);
void			quick_sort2(t_stack *a, t_stack *b);
void			sort3(t_stack *a);
void			sort5(t_stack *a, t_stack *b);

#endif
