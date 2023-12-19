/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/18 23:23:59 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rot_to_first(t_nlst **a, int n)
{
	int flag;

	flag = (nlst_get_place(a, nlst_get_low_big(a, 0)) <= n / 2);
	while (!check_first(a, 0))
	{
		if (flag)
			rotate(a, 0);
		else 
			reverse_rotate(a, 0);
	}
}

static t_nlst	**sort_n(t_nlst **a,t_nlst **b , int n)
{
	if (n == 2)
		swap(a, 0);
	else if (n == 3)
	{
		if (!check_only_need_rot(a))
			swap(a, 0);
		rot_to_first(a, n);
	}
	else
	{
		if (check_only_need_rot(a))
			rot_to_first(a, n);
		else
		{
			rot_to_first(a, n);
			push(a, b, 0);
			sort_n(a, b, n - 1);
			push(b, a, 1);
		}
	}
	return (a);
}

void ps_sort(t_nlst **a, t_nlst **b)
{
	int	size;
	size = ft_nlstsize(*a);
	if (check_only_swap(a, size))
		swap(a, 0);
	if (!check_heap(a))
		sort_n(a, b, size);
}
