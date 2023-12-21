/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 21:08:56 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nlst **a, t_nlst **b, int a_b)
{
	t_nlst	*tmp;

	if (!*a)
		return ;
	(*a)->move++;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (a_b)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	swap(t_nlst **l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	(*l)->move++;
	tmp = (*l)->next;
	tmp2 = tmp->next;
	(*l)->next = tmp2;
	tmp->next = *l;
	*l = tmp;
	if (!a_b)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	rotate(t_nlst **l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	(*l)->move++;
	tmp = *l;
	*l = tmp->next;
	tmp2 = *l;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (!a_b)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(t_nlst **a, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	(*a)->move++;
	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	tmp2->next = NULL;
	*a = tmp;
	if (!a_b)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
