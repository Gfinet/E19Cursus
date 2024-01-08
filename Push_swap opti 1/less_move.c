/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:07:19 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/08 17:59:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_all_bigger_lower(t_nlst_head *b, int cur, int a_b)
{
	int flag;
	t_nlst *tmp;

	flag = 1;
	tmp = b->first;
	while (tmp && flag)
	{
		if (tmp->content > cur)
			flag = 0;
	tmp = tmp->next;
	}
	if (flag)
		return (nlst_get_place(b, nlst_get_low_big(b, !a_b)));
	tmp = b->first;
	while (tmp && !flag)
	{
		if (tmp->content < cur)
			flag = 1;
	tmp = tmp->next;
	}
	if (!flag)
		return (nlst_get_place(b,  nlst_get_low_big(b, !a_b)));
	return (-1);
}
int	compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b)
{
	int	count;
	t_nlst *tmp;
	t_nlst *prev;
	
	count = check_all_bigger_lower(b, cur->content, a_b);
	if (count == -1)
	{
		count ++;
		tmp = b->first;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
			if (!tmp)
				tmp = b->first;
			if (!a_b)
			{
				if (prev->content > cur->content && 
					tmp->content < cur->content)
					break;
			}
			else
			{
				if (prev->content < cur->content && 
					tmp->content > cur->content)
					break;
			}
			count ++;
		}
	}
	count = (ft_nlstsize(b) != count) * count;
	count += !count;
	if (count > ft_nlstsize(b) / 2)
		count = ft_nlstsize(b) - count;
	if (nlst_get_place(a, cur->content) < ft_nlstsize(a) / 2)
		count += nlst_get_place(a, cur->content) - 1;
	else
		count += ft_nlstsize(a) - nlst_get_place(a, cur->content) + 1;
	ft_printf("val = %i ", cur->content);
	ft_printf("- count = %i\n", count);
	return (count);
}

int	find_less_move(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	t_nlst *cur;
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
			break;
	}
	return (best_node);
}

static void choose_rotate(t_nlst_head *a, t_nlst_head *b, int flag, int flag2)
{
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

int get_next(t_nlst_head *b, int val, int a_b)
{
	int best;
	int ind;
	t_nlst *tmp;
	t_nlst *prev;

	tmp = b->first;
	prev = tmp;
	best = tmp->content;
	ind = check_all_bigger_lower(b, val, a_b);
	ft_printf("ind = %i\n", ind);
	if ( ind != -1)
		return (get_node(b, ind)->content);
	while (prev->next)
		prev = prev->next;
	while (tmp)
	{
		if (prev->content > val && tmp->content < val)
		{
			best = tmp->content;
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (best);
}

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
{
	int		flag;
	int		flag2;
	int		futur_next;

	futur_next = get_next(b, val, a_b);
	flag = (nlst_get_place(a, val) < ft_nlstsize(a) / 2);
	flag2 = (nlst_get_place(b, futur_next) < ft_nlstsize(b) / 2);
	ft_printf("f_next : %i\n", futur_next);
	while (a->first && b->first && 
	(a->first->content != val || b->first->content != futur_next))
	{
		if (a->first->content != val && b->first->content != futur_next)
			choose_rotate(a, b, flag, flag2);
		else
		{
			if (a->first->content != val)
				choose_rotate(a, 0, flag, flag2);
			if (b->first->content != futur_next)
				choose_rotate(0, b, flag, flag2);
		}
	}
	push(a, b, a_b);
}
