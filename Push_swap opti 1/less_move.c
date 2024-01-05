/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:07:19 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/04 17:07:44 by Gfinet           ###   ########.fr       */
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
	return (count);
}

int	find_less_move(t_nlst_head *a, t_nlst_head *b)
{
	t_nlst *cur;
	int		best;
	int		best_node;

	best = ft_nlstsize(b) * ft_nlstsize(b);
	best_node = 0;
	cur = b->first;
	while (cur)
	{
		if (compute_moves(a, b, cur) < best || best_node == 0)
		{
			best = compute_moves(a, b, cur);
			best_node = cur->content;
		}
		cur = cur->next;
	}
	printf("n_best = %i\nbest = %i\n", best_node, best);
	return (best_node);
}

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
{
	int		flag;
	int		closer;

	ft_printf(" v = %i ", val);
	flag = (nlst_get_place(b, val) < ft_nlstsize(b) / 2);
	while (b->first && b->first->content != val)
	{
		if (flag)
			rotate(b, 0, a_b);
		else
			reverse_rotate(b, 0, a_b);
		sleep(1);
		ft_printf("yo %i ", b->first->content);
	}
	closer = get_closer(a, b->first->content);
	flag = (nlst_get_place(a, closer) < ft_nlstsize(a) / 2);
	while (a->first->content != closer)
	{
		if (flag)
			rotate(a, 0, !a_b);
		else
			reverse_rotate(a, 0, !a_b);
		sleep(1);
		ft_printf("yo %i ", b->first->content);
	}
	push(b, a, a_b);
}

// void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
// {
// 	int		flag;
// 	int		flag2;
// 	int		closer;

// 	ft_printf(" v = %i ", val);
// 	closer = get_closer(a, b->first->content);
// 	flag = (nlst_get_place(b, val) < ft_nlstsize(b) / 2);
// 	flag2 = (nlst_get_place(a, closer) < ft_nlstsize(a) / 2);
// 	while ((b->first && b->first->content != val) || a->first->content != closer)
// 	{
// 		if (flag && flag2)
// 			rotate(a, b, 2);
// 		else if (!flag && !flag2)
// 			reverse_rotate(a, b, 2);
// 		else if (flag && !flag2)
// 			rotate(b, 0, a_b);
// 		else if (!flag && flag2)
// 			reverse_rotate(b, 0, a_b);
// 		sleep(1);
// 		ft_printf("yo %i ", b->first->content);
// 	}
// 	push(b, a, a_b);
// }