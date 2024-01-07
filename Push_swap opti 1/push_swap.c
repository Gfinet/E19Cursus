/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:21:32 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/07 01:44:52 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	fill_a(t_nlst_head *a, char **arg, int nb_arg)
{
	t_nlst  *p;
	int	 i;

	i = 0;
	while (i < nb_arg)
	{
		p = ft_nlstnew(ft_atoi(arg[i]));
		if (!p)
			return (ft_nlstclear(a, free));
		ft_nlstadd_back(a, p);
		i++;
	}
	return (1);
}

t_res *push_swap(char **arg, int nb_arg)
{
	t_nlst_head  	*a;
	t_nlst_head  	*b;
	t_res 			*res;

	nlst_head_init(&a);
	nlst_head_init(&b);
	res_init(&res);
	
		
	if (!fill_a(a, arg, nb_arg))
		return (res);
	a->lower = nlst_get_low_big(a, 0);
	print_list(a);
	ft_printf("min = %d\n", a->lower);
	opti_push(a, b, 0);
	
	ft_printf("\n");
	print_list(a);
	int i = 0;
	t_nlst *p =a->first;
	
	while (p)
	{
		i = p->move + i;
		p = p->next;
	}
	ft_printf("moves : %i\n", i);
	res->moves = nlst_compute_moves(a);
	res->sorted = check_heap(a->first, 0);
	ft_nlstclear(a, free);
	ft_nlstclear(b, free);
	return (res);
}

