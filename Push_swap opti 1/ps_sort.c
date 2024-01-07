/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/07 01:59:56 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void print_list(t_nlst_head *a)
{
	t_nlst *p;

	p = a->first;
	while (p)
	{
		ft_printf("%i ", p->content);
		p = p->next;
	}
	ft_printf("\n");
}

void rot_to_first(t_nlst_head *a, int num, int n, int a_b)
{
	int flag;

	flag = (nlst_get_place(a, num) <= n / 2);
	while (!check_first(a, a_b))
	{
		if (flag)
			rotate(a, 0, a_b);
		else 
			reverse_rotate(a, 0, a_b);
	}
}


void	sort_3(t_nlst_head *a, int a_b)
{
	t_nlst *p1;
	t_nlst *p2;
	t_nlst *p3;

	p1 = a->first;
	p2 = p1->next;
	p3 = p2->next;
	if (a_b)
	{
		if (p1->content < p2->content && p2->content < p3->content)
			swap(a, 0, a_b);
		else if (p1->content > p2->content && p2->content < p3->content)
			swap(a, 0, a_b);
		else if (p1->content < p2->content && p2->content > p3->content)
			swap(a, 0, a_b);
	}
	else
	{
		if (p1->content > p2->content && p2->content > p3->content)
			swap(a, 0, a_b);
		else if (p1->content < p2->content && p2->content > p3->content)
			swap(a, 0, a_b);
		else if (p1->content > p2->content && p2->content < p3->content)
			swap(a, 0, a_b);
	}
}

void opti_push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	int	best_node;

	while (ft_nlstsize(b) < 3)
			push(a,b, a_b);
	sort_3(b, 1);
	best_node = find_less_move(a, b);
	while (best_node != 0)
	{
		move_faster_node(a, b, best_node, a_b);
		best_node = find_less_move(a,b);
	}
	while(ft_nlstsize(b) != 0)
		push(b, a, !a_b);
	rot_to_first(a, a->lower, ft_nlstsize(a), 0);
}
