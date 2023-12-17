/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/16 18:51:05 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nlst **a, t_nlst **b)
{
	t_nlst	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
}

void	swap(t_nlst **l)
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
}

void	rotate(t_nlst **l)
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
}

void	reverse_rotate(t_nlst **l)
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
}
