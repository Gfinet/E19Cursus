/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 17:13:15 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rot_to_first(t_nlst **a, int n, int a_b)
{
	int flag;

	flag = (nlst_get_place(a, nlst_get_low_big(a, a_b)) <= n / 2);
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

static t_nlst	**sort_n(t_nlst **a,t_nlst **b , int n, int a_b)
{
	if (n < 2)
		return (0);
	if (n == 2)
		swap(a, a_b);
	else if (n == 3)
	{
		if (!check_only_need_rot(a, a_b))
			swap(a, a_b);
		rot_to_first(a, n, a_b);
	}
	else
	{
		rot_to_first(a, n, a_b);
		if (!check_heap(a, a_b))
		{
			rot_to_first(a, n, a_b);
			push(a, b, a_b);
			sort_n(a, b, n - 1, a_b);
			push(b, a, !a_b);
		}
	}
	return (a);
}
void ps_sort(t_nlst **a, t_nlst **b)
{
	int	size;
	size = ft_nlstsize(*a);
	if (check_swap(a, 0))
		swap(a, 0);

	
	if (!check_heap(a, 0))
		sort_n(a, b, size, 0);
}
