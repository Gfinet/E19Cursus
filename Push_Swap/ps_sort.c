/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:21 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 13:52:10 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_heap(t_nlst **a)
{
	t_nlst	*p;

	p = *a;
	if (!*a)
		return (0);
	while (p->next)
	{
		if (p->content > p->next->content)
			return (0);
		p = p->next;
	}
	return (1);
}

static int	check_first(t_nlst **a, int low_big)
{
	int 	low;
	t_nlst	*tmp;

	if (!*a)
		return (0);
	tmp = (*a)->next;
	low = (*a)->content;
	while (tmp != NULL)
	{
		if (!low_big && tmp->content < low)
			return (0);
		else if (low_big && tmp->content > low)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_nlst	**sort_n(t_nlst **a,t_nlst **b , int n)
{
	if (n == 2)
	{
		if (!check_heap(a))
		{
			rotate(a);
			ft_printf("ra ");
		}
	}
	else
	{
		if (nlst_get_place(a, nlst_get_low(a)) <= n / 2)
		{
			while (!check_first(a, 0))
			{
				ft_printf("ra ");
				rotate(a);
			}
		}
		else
		{
			while (!check_first(a, 0))
			{
				ft_printf("rra ");
				reverse_rotate(a);
			}
		}
		push(a, b);
		ft_printf("pa ");
		sort_n(a, b, n - 1);
		push(b, a);
		ft_printf("pb ");
	}
	return (a);
}

void ps_sort(t_nlst **a, t_nlst **b)
{
	int	size;
	
	size = ft_nlstsize(*a);
	if (size == 2)
	{
		if (sort_n(a, b, size) != a)
			ft_printf("ra");
	}
	else
	{
		printf("\n3 %i %i\n", check_first(a, 0), ft_nlstsize(*a));
		sort_n(a, b, size);
	}
}
