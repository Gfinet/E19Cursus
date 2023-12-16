/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/13 22:23:32 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_heap(t_nlst **a)
{
	t_nlst	*p;
	
	if (!*a)

	p = *a;
	while (p->next)
		if (p->content > p->next->content)
			return (0);
	return (1);
}

static int	check_first(t_nlst **a, int low_big)
{
	int 	low;
	t_nlst	*tmp;
	
	tmp = *a;
	low = (*a)->content;
	while (tmp->next)
			if (!low && tmp->content < low)
				return (0);
			else if (low && tmp->content > low)
				return (0);
	return (1);
}

static t_nlst	**sort_n(t_nlst **a,t_nlst **b , int n)
{
	if (n == 2)
		if (!check_heap(a))
			rotate(a);
	else if (n == 3)
	{
		
		if (!check_first(a, 0))
			rotate(a);
		else if (!check_first)
		push(a, b);
		sort_n(a, b, n--);
		push(b, a);
	}
	return (a);
}

void ps_sort(t_nlst **a, t_nlst **b)
{
	int	size;
	
	size = ft_nlstsize(a);
	if (size == 2)
		if (sort_n(a, b, size) != a)
			ft_printf("ra");
	else if (size == 3)
		sort_n(a, b, size);
}