/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/12 19:28:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
}

void	swap(t_list **l)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	tmp = (*l)->next;
	tmp2 = tmp->next;
	(*l)->next = tmp2;
	tmp->next = *l;
	*l = tmp;
}

void	rotate(t_list **l)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*l || !(*l)->next)
		return ;
	tmp = *l;
	*l = tmp->next;
	tmp2 = *l;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_list **l)
{
	t_list	*tmp;
	t_list	*tmp2;

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
}
