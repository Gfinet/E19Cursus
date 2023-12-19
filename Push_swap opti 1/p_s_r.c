/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/18 23:06:45 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nlst **a, t_nlst **b, int a_b)
{
	t_nlst	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (!a_b)
		ft_printf("pa ");
	else
		ft_printf("pb ");
}

void	swap(t_nlst **l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	tmp = (*l)->next;
	tmp2 = tmp->next;
	(*l)->next = tmp2;
	tmp->next = *l;
	*l = tmp;
	if (!a_b)
		ft_printf("sa ");
	else
		ft_printf("sb ");
}

void	rotate(t_nlst **l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	tmp = *l;
	*l = tmp->next;
	tmp2 = *l;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (!a_b)
		ft_printf("ra ");
	else
		ft_printf("rb ");
}

void	reverse_rotate(t_nlst **l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	tmp = *l;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = *l;
	tmp2->next = NULL;
	*l = tmp;
	if (!a_b)
		ft_printf("rra ");
	else
		ft_printf("rrb ");
}
