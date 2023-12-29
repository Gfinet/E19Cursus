/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/28 18:28:33 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	t_nlst	*tmp;

	if (!a)
		return ;
	a->first->move++;
	tmp = b->first;
	b->first = a->first;
	a->first = a->first->next;
	b->first->next = tmp;
	if (a_b)
		ft_printf("pa%c", SEP);
	else
		ft_printf("pb%c", SEP);
}

void	swap(t_nlst_head *l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!l)
		return ;
	if (!l->first)
		return ;
	l->first->move++;
	tmp = l->first->next;
	tmp2 = tmp->next;
	l->first->next = tmp2;
	tmp->next = l->first;
	l->first = tmp;
	if (!a_b)
		ft_printf("sa%c", SEP);
	else
		ft_printf("sb%c", SEP);
}

void	rotate(t_nlst_head *l, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!l)
		return ;
	if (!l->first)
		return ;
	l->first->move++;
	tmp = l->first;
	l->first = tmp->next;
	tmp2 = l->first;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (!a_b)
		ft_printf("ra%c", SEP);
	else
		ft_printf("rb%c", SEP);
}

void	reverse_rotate(t_nlst_head *a, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (!a)
		return ;
	if (!a->first)
		return ;
	a->first->move++;
	tmp = a->first;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = a->first;
	tmp2->next = NULL;
	a->first = tmp;
	if (!a_b)
		ft_printf("rra%c", SEP);
	else
		ft_printf("rrb%c", SEP);
}
