/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:21:32 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/16 23:56:47 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fill the a pile with all char number translate into int number.

static int	fill_a(t_nlst_head *a, char **arg, int nb_arg)
{
	t_nlst	*p;
	int		i;

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

static void	sort_little(t_nlst_head *a, t_nlst_head *b, int n)
{
	if (check_heap(a->first, 0))
		return ;
	if (n == 2)
	{
		if (!check_heap(a->first, 0))
			rotate(a, 0, 0);
	}
	else
	{
		if (nlst_get_place(a, nlst_get_low_big(a, 0)) <= n / 2)
			while (!check_first(a, 0))
				rotate(a, 0, 0);
		else
			while (!check_first(a, 0))
				reverse_rotate(a, 0, 0);
		push(a, b, 0);
		sort_little(a, b, n - 1);
		push(b, a, 1);
	}
}

t_res	*push_swap(char **arg, int nb_arg)
{
	t_nlst_head		*a;
	t_nlst_head		*b;
	t_res			*res;

	nlst_head_init(&a);
	nlst_head_init(&b);
	res_init(&res);
	if (!fill_a(a, arg, nb_arg))
		return (res);
	a->lower = nlst_get_low_big(a, 0);
	if (ft_nlstsize(a) > 5)
		opti_push(a, b, 0);
	else
		sort_little(a, b, ft_nlstsize(a));
	res->moves = nlst_compute_moves(a);
	res->sorted = check_heap(a->first, 0);
	ft_nlstclear(a, free);
	ft_nlstclear(b, free);
	return (res);
}
