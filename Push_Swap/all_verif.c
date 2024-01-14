/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:58:42 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/13 20:41:21 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_heap(t_nlst *a, int a_b)
{
	t_nlst	*p;

	if (!a)
		return (0);
	p = a;
	while (p->next)
	{
		if (!a_b && p->content > p->next->content)
			return (0);
		else if (a_b && p->content < p->next->content)
			return (0);
		p = p->next;
	}
	return (1);
}

int	check_first(t_nlst_head *a, int a_b)
{
	int		low;
	t_nlst	*tmp;

	if (!a)
		return (0);
	if (!a->first)
		return (0);
	tmp = a->first->next;
	low = a->first->content;
	while (tmp != NULL)
	{
		if (!a_b && tmp->content < low)
			return (0);
		else if (a_b && tmp->content > low)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_only_need_rot(t_nlst_head *a, int a_b)
{
	t_nlst	*p;

	p = a->first;
	if (!p)
		return (0);
	if (!a_b)
		while (p->next && p->content < p->next->content)
			p = p->next;
	else
		while (p->next && p->content > p->next->content)
			p = p->next;
	if (!p->next || p->content != nlst_get_low_big(a, !a_b))
		return (0);
	p = p->next;
	while (p->next && p->content < p->next->content)
	{
		if (!a_b && p->content > a->first->content)
			return (0);
		else if (a_b && p->content < a->first->content)
			return (0);
		p = p->next;
	}
	if (p->content > a->first->content)
		return (0);
	return (p->next == NULL);
}

int	check_only_swap(t_nlst_head *a, int size, int a_b)
{
	t_nlst	*p;
	int		c;
	int		b;
	int		d;

	p = a->first;
	if (size < 3)
		return (0);
	if (!a_b)
	{
		c = (p->content < p->next->next->content);
		b = (p->next->content < p->next->next->content);
		d = a->first->content > a->first->next->content;
	}
	else
	{
		c = (p->content > p->next->next->content);
		b = (p->next->content > p->next->next->content);
		d = a->first->content < a->first->next->content;
	}
	if (c && b)
		p = a->first->next->next;
	else
		return (0);
	return (check_heap(p, a_b) && d);
}

int	check_swap(t_nlst_head *a, int a_b)
{
	t_nlst	*p;

	p = a->first;
	if (!a_b && p->content > p->next->content)
		return (1);
	else if (a_b && p->content < p->next->content)
		return (1);
	else
		return (0);
}
