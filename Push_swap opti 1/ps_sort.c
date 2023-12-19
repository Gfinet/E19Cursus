/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/19 18:47:19 by gfinet           ###   ########.fr       */
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

static t_nlst	**sort_n(t_nlst **a,t_nlst **b , int n, int a_b)
{
	if (n < 2)
		return (0);
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
			push(a, b, (0 == a_b));
			sort_n(a, b, n - 1, a_b);
			push(b, a, (1 == a_b));
		}
	}
	return (a);
}

int get_median(t_nlst **a, int nb_elem)
{
	int tot;
	int lower;
	int bigger;
	t_nlst *p;

	p = *a;
	tot = 0;
	while (p)
	{
		tot += p->content; 
		p = p->next;
	}
	tot /= nb_elem;
	p = *a;
	bigger = 0;
	lower = 0;
	while (p)
	{
		bigger += 1 * (p->content > tot);
		lower += 1 * (p->content < tot);
	}
	return (bigger - lower);
}

void ps_sort(t_nlst **a, t_nlst **b)
{
	int	size;
	size = ft_nlstsize(*a);
	if (check_only_swap(a, size, 0))
		swap(a, 0);

	
	if (!check_heap(a, 0))
		sort_n(a, b, size, 0);
}

//void ps_sort(t_nlst **a, t_nlst **b) // bad opti
// {
// 	int	size_a;
// 	int size_b;
// 	int nb_elem;
	
// 	nb_elem = ft_nlstsize(*a);
// 	while (ft_nlstsize(*a) > nb_elem / 2)
// 		push(a, b, 0);
// 	size_b = ft_nlstsize(*b);
// 	if (check_only_swap(b, size_b, 1))
// 		swap(b, 1);
// 	else if (!check_heap(b, 1))
// 		sort_n(b, a, size_b, 1);
	
// 	size_a = ft_nlstsize(*a);
// 	if (check_only_swap(a, size_a, 0))
// 		swap(a, 0);
// 	else if (!check_heap(a, 0))
// 		sort_n(a, b, size_a, 0);
// 	while (ft_nlstsize(*b) > 0)
// 		if ((*b)->content > (*a)->content)
// 			rotate(a, 0);
// 		else
// 			push(b, a, 1);
// 	rot_to_first(a, 0);
// }