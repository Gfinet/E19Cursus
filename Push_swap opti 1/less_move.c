/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:07:19 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/04 01:05:32 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur)
{
	int	count;

	count = nlst_get_place(a, get_closer(a, cur->content)) + 1;
	if (nlst_get_place(b, cur->content) < ft_nlstsize(b) / 2)
		count += nlst_get_place(b, cur->content);
	else
		count += ft_nlstsize(b) - nlst_get_place(b, cur->content) + 1;
	ft_printf("count = %i\n", count);
	return (count);
}

int	find_less_move(t_nlst_head *a, t_nlst_head *b)
{
	t_nlst *cur;
	int		best;
	int		n_best;

	best = 0;
	n_best = ft_nlstsize(b);
	cur = b->first;
	while (cur)
	{
		if (compute_moves(a, b, cur) < best)
		{
			best = compute_moves(a, b, cur);
			n_best = cur->content;
		}
		cur = cur->next;
	}
	ft_printf("n_best = %i\n", n_best);
	return (n_best);
}

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
{
	int		flag;

	ft_printf(" v = %i ", val);
	flag = (nlst_get_place(b, val) < ft_nlstsize(b) / 2);
	while (b->first && b->first->content != val)
	{
		if (flag)
			rotate(b, 0, a_b);
		else
			reverse_rotate(b, 0, a_b);
		sleep(1);
		ft_printf(" %i ", b->first->content);
	}
	push(b, a, a_b);
}
