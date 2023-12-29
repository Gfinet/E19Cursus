/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/29 07:35:23 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rot_to_first(t_nlst_head *a, int num, int n, int a_b)
{
	int flag;

	flag = (nlst_get_place(a, num) <= n / 2);
	while (!check_first(a, a_b))
	{
		if (flag)
			rotate(a, a_b);
		else 
			reverse_rotate(a, a_b);
		if (check_swap(a, a_b))
			swap (a, a_b);
	}
}

static int	sort_3(t_nlst_head *a, t_nlst *b, int a_b)
{
	if (!check_only_need_rot(a, a_b))
		swap(a, a_b);
	rot_to_first(a, nlst_get_low_big(a, a_b), 3, a_b);
}

static t_nlst	**sort_n(t_nlst_head *a,t_nlst_head *b , int n, int a_b)
{
	if (n < 2)
		return (0);
	if (n == 2)
		swap(a, a_b);
	else
	{
		rot_to_first(a, nlst_get_low_big(a, a_b), n, a_b);
		if (!check_heap(&a->first, a_b))
		{
			rot_to_first(a, nlst_get_low_big(a, a_b), n, a_b);
			push(a, b, a_b);
			sort_n(a, b, n - 1, a_b);
			push(b, a, !a_b);
		}
	}
	return (&a->first);
}

void ps_sort(t_nlst_head *a, t_nlst_head *b)
{
	int size;

	if (check_only_need_rot(a, 0))
		rot_to_first(a, nlst_get_low_big(a, 0), ft_nlstsize(a), 0);
	else if (check_swap(a, 0))
		swap(a, 0);
	else if (!check_heap(&a->first, 0))
	{
		size = ft_nlstsize(a);
		while (ft_nlstsize(a) > 3)
		{
			if (!nlst_is_need_val(a, a->first->content))
				push(a, b, 0);
			else
				rotate(a, 0);
		}
		sort_3(a, b, 0);
		if (size <= 9 && size > 3)
		{
			rotate(a, 0);
			sort_n(a, b, size, 0);
		}
	}
}

// void ps_sort(t_nlst **a, t_nlst **b)
// {
// 	int	size;
// 	size = ft_nlstsize(*a);
// 	if (check_only_need_rot(a, 0))
// 		rot_to_first(a, ft_nlstsize(*a), 0);
// 	else if (check_swap(a, 0))
// 		swap(a, 0);
	
// 	if (!check_heap(a, 0))
// 		sort_n(a, b, size, 0);
// }
