/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:58:42 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/18 23:25:35 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_heap(t_nlst **a)
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

int	check_first(t_nlst **a, int low_big)
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

int	check_only_need_rot(t_nlst **a)
{
	t_nlst *p;

	p = *a;
	if (!*a)
		return (0);
	while (p->next && p->content < p->next->content)
		p = p->next;
	if (!p->next || p->content != nlst_get_low_big(a, 1))
		return (0);
	p = p->next;
	while (p->next && p->content < p->next->content)
	{
		if (p->content > (*a)->content)
			return (0);
		p = p->next;
	}
	if (p->content > (*a)->content)
		return (0);
	return (p->next == NULL);
}
int	check_only_swap(t_nlst **a, int size)
{
	t_nlst *p;
	int c;
	int b;

	p = (*a);
	if (size < 3)
		return (0);
	c = (p->content < p->next->next->content);
	b = (p->next->content < p->next->next->content);
	if (c && b)
		p = (*a)->next->next;
	else
		return (0);
	if (check_heap(&p) && (*a)->content > (*a)->next->content)
		return (1);
	return (0);
}
