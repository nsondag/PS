/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsondag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:43:18 by nsondag           #+#    #+#             */
/*   Updated: 2018/12/02 21:52:37 by nsondag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		parser(t_stack *a, char **argv, int argc)
{
	int check;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		check = check_validity2(argv[1]);
		*a = get_numbers2(argv[1]);
	}
	else
	{
		check = check_validity(&argv[1]);
		*a = get_numbers(&argv[1]);
	}
	if (check && a->tab)
		return (1);
	else
		return (-1);
}
