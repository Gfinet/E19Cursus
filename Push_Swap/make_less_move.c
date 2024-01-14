/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_less_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:07:19 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/14 19:57:26 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_less_move(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	t_nlst	*cur;
	int		best;
	int		best_node;
	int		comp_moves;

	if (!a->first)
		return (0);
	best = ft_nlstsize(a) * ft_nlstsize(a) + 1;
	if (ft_nlstsize(a) < ft_nlstsize(b))
		best = ft_nlstsize(b) * ft_nlstsize(b);
	best_node = 0;
	cur = a->first;
	while (cur)
	{
		comp_moves = compute_moves(a, b, cur, a_b);
		if (comp_moves < best)
		{
			best = comp_moves;
			best_node = cur->content;
		}
		cur = cur->next;
		if (best == 0 || best == 1)
			break ;
	}
	return (best_node);
}

static void	choose_rotate(t_nlst_head *a, t_nlst_head *b, t_2_flag f, int a_b)
{
	if (a && b && f.one == f.two)
	{
		if (f.one && f.two)
			rotate(a, b, 2);
		else if (!f.one && !f.two)
			reverse_rotate(a, b, 2);
	}
	else
	{
		if (a && f.one)
			rotate(a, 0, a_b);
		else if (a && !f.one)
			reverse_rotate(a, 0, a_b);
		if (b && f.two)
			rotate(b, 0, !a_b);
		else if (b && !f.two)
			reverse_rotate(b, 0, !a_b);
	}
}

int	get_next(t_nlst_head *b, int val, int a_b)
{
	int		best;
	int		ind;
	t_nlst	*tmp;
	t_nlst	*prev;

	tmp = b->first;
	prev = tmp;
	best = tmp->content;
	ind = check_all_bigger_lower(b, val, a_b);
	if (ind != -1)
		return (get_node(b, ind)->content);
	while (prev->next)
		prev = prev->next;
	while (tmp && ind)
	{
		if ((!a_b && prev->content > val && tmp->content < val)
			|| (a_b && prev->content < val && tmp->content > val))
		{
			best = tmp->content;
			ind = 0;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (best);
}

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
{
	t_2_flag	f;
	int			futur_next;

	futur_next = get_next(b, val, a_b);
	f.one = (nlst_get_place(a, val) < ft_nlstsize(a) / 2);
	f.two = (nlst_get_place(b, futur_next) < ft_nlstsize(b) / 2);
	while (a->first && b->first && 
		(a->first->content != val || b->first->content != futur_next))
	{
		if (a->first->content != val && b->first->content != futur_next)
			choose_rotate(a, b, f, a_b);
		else
		{
			if (a->first->content != val)
				choose_rotate(a, 0, f, a_b);
			if (b->first->content != futur_next)
				choose_rotate(0, b, f, a_b);
		}
	}
	push(a, b, !a_b);
}
