/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/31 14:40:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//optionnal printing function of a or b because of a_b
//0 : a / 1 : b

void	print_list(t_nlst_head *a, int a_b)
{
	t_nlst	*p;
	char	c;

	c = a_b * 'b' + !a_b * 'a';
	p = a->first;
	ft_printf("%c : ", c);
	while (p)
	{
		ft_printf("%i ", p->content);
		p = p->next;
	}
	ft_printf("\n");
}

//function will put the lower or bigger in the first place of the pile
//a_b(0) : lower / a_b(1) : bigger

void	rot_to_first(t_nlst_head *a, int num, int n, int a_b)
{
	int	flag;

	flag = (nlst_get_place(a, num) - 1 <= n / 2);
	while (!check_first(a, a_b))
	{
		if (flag)
			rotate(a, 0, a_b);
		else
			reverse_rotate(a, 0, a_b);
	}
}

//Function which sort a pile of 3 number depending of a_b
//0 : lower to bigger / 1 : bigger to lower

void	sort_3(t_nlst_head *a, int a_b)
{
	if (!check_only_need_rot(a, a_b) && !check_heap(a->first, 0))
		swap(a, 0, a_b);
}

//Function wich push all number into either the top or the bottom of b.
//If the first element is lower than average (m), it's stay on top else,
//it goes on bottom.

void	pre_sort(t_nlst_head *a, t_nlst_head *b)
{
	int		m;
	t_nlst	*p;

	p = a->first;
	m = 0;
	while (p)
	{
		m += p->content;
		p = p->next;
	}
	m /= ft_nlstsize(a);
	while (!(ft_nlstsize(a) == 3) && !check_only_need_rot(a, 0))
	{
		push(a, b, 1);
		if (b->first->content >= m)
			rotate(b, 0, 1);
	}
}

//Algorythm wich sort the 2 piles.
//Starting with pushing the 3 first value form a to b and sorting b.
//then will move the faster node from a to b until 3 nodes left in a.
//Sort the 3 last nodes in a before moving the fatser nodes from b to a.
//Finishing by putting the lower node in the first position.

void	opti_push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	int	best_node;

	if (check_heap(a->first, 0))
		return ;
	while (ft_nlstsize(b) < 3)
		push(a, b, !a_b);
	sort_3(b, 1);
	pre_sort(a, b);
	if (ft_nlstsize(a) == 3 && !check_heap(a->first, 0))
		sort_3(a, 0);
	best_node = find_less_move(b, a, !a_b);
	while (ft_nlstsize(b) != 0)
	{
		move_faster_node(b, a, best_node, !a_b);
		best_node = find_less_move(b, a, !a_b);
	}
	rot_to_first(a, a->lower, ft_nlstsize(a), 0);
}
