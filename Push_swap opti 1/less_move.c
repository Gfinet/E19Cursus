/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:07:19 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/05 22:03:53 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur)
{
	int	count;
	t_nlst *tmp;
	
	count = 0;
	tmp = b->first;
	while (tmp->next)
	{
		while (tmp->next && cur->content > tmp->content)
			tmp = tmp->next;
		if (cur->content < tmp->content)
			count++;
		tmp = tmp->next;
	}
	count = (ft_nlstsize(b) != count) * count;
	if (!count)
		count++;
	else if (count > ft_nlstsize(b) / 2)
		count = ft_nlstsize(b) - count;
	if (nlst_get_place(a, cur->content) < ft_nlstsize(a) / 2)
		count += nlst_get_place(a, cur->content);
	else
		count += ft_nlstsize(a) - nlst_get_place(a, cur->content) + 1;
	return (count);
}

int	find_less_move(t_nlst_head *a, t_nlst_head *b)
{
	ft_printf("less_move\n");
	t_nlst *cur;
	int		best;
	int		best_node;
	int		comp_moves;

	if (ft_nlstsize(a) == 0)
		return (0);
	best = ft_nlstsize(a) * ft_nlstsize(a);
	best_node = 0;
	cur = a->first;
	while (cur)
	{
		comp_moves = compute_moves(a, b, cur);
		if (comp_moves < best || best_node == 0)
		{
			best = comp_moves;
			best_node = cur->content;
		}
		cur = cur->next;
	}
	ft_printf("best_node = %i best_moves = %i\n", best_node, best);
	return (best_node);
}

static void choose_rotate(t_nlst_head *a, t_nlst_head *b, int flag, int flag2)
{
	ft_printf("choose_rot\n");
	if (a && b && flag == flag2)
	{
		if (flag && flag2)
			rotate(a, b, 2);
		else if (!flag && !flag2)
			reverse_rotate(a, b, 2);
	}
	else
	{
		if (a && flag)
			rotate(a, 0, 0);
		else if (a && !flag)
			reverse_rotate(a, 0, 0);
		if (b && flag2)
			rotate(b, 0, 1);
		else if (b && !flag2)
			reverse_rotate(b, 0, 1);
	}
}

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
{
	int		flag;
	int		flag2;
	int		futur_next;

	ft_printf("move_fast\n");
	futur_next = get_next(val, b);
	flag = (nlst_get_place(a, val) < ft_nlstsize(a) / 2);
	flag2 = (nlst_get_place(b, futur_next) < ft_nlstsize(b) / 2);
	while (a->first && b->first && 
	(a->first->content != val || b->first->content != futur_next))
	{
		ft_printf("bite\n");
		if (a->first->content != val && b->first->content != futur_next)
			choose_rotate(a, b, flag, flag2);
		else
		{
			if (a->first->content != val)
				choose_rotate(a, 0, flag, flag2);
			if (b->first->content != futur_next)
				choose_rotate(0, b, flag, flag2);
		}
		sleep(1);
	}
	push(a, b, a_b);
}

void opti_push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	int	best_node;

	ft_printf("opti_push\n");
	if (!b->first)
			push(a,b, a_b);
	best_node = find_less_move(a, b);
	while (best_node != 0)
	{
		move_faster_node(a, b, best_node, a_b);
		best_node = find_less_move(a,b);
	}
	while(ft_nlstsize(b) != 0)
		push(b, a, !a_b);

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