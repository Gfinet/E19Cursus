/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:09:33 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/14 23:14:47 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_imaginary_list(t_nlst_head *l, t_nlst *cur, t_nlst *p, int a_b)
{
	int		i;
	int		size;
	int		*m;

	size = ft_nlstsize(l) + (1 * a_b - 1 * !a_b);
	m = malloc(sizeof(int) + size);
	if (!m)
		return (0);
	if (a_b)
		m[0] = cur->content;
	i = a_b;
	while (i < size)
	{
		m[i] = p->content;
		p = p->next;
		if (!p)
			p = l->first;
		i++;
	}
	return (m);
}

int	guess_second(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b)
{
	int		*a2;
	int		*b2;
	int		next;
	t_nlst	*p;

	next = get_next(b, cur->content, a_b);
	p = b->first;
	while (p && p->content != next)
		p = p->next;	
	b2 = init_imaginary_list(b, cur, p, !a_b);
	if (!b2)
		return (ft_nlstsize(a) * ft_nlstsize(b));
	p = a->first;
	if (cur->next)
	{
		while (p && p != cur)
			p = p->next;
		p = p->next;
	}
	a2 = init_imaginary_list(a, cur, p, a_b);
	if (!a2)
		return (ft_nlstsize(a) * ft_nlstsize(b));
	free(a2);
	free(b2);
}


/*
	next = get_next(b, cur->content, a_b);
	p = b->first;
	while (p && p->content != next)
		p = p->next;
	
	b2 = malloc(sizeof(int) * (ft_nlstsize(b) + 1));
	b2[0] = cur->content;
	i = 1; //a_b
	while (i < ft_nlstsize(b) + 1) //size / L et a_b
	{
		b2[i] = p->content; // L
		p = p->next;
		if (!p)
			p = b->first;
		i++;
	}

	i = 0;
	p = a->first;
	if (cur->next)
	{
		while (p && p != cur)
			p = p->next;
		p = p->next;
	}

	a2 = malloc(sizeof(int) * (ft_nlstsize(a) - 1));
	i = 0;
	while (i < ft_nlstsize(a) - 1)
	{
		a2[i] = p->content;
		p = p->next;
		if (!p)
			p = a->first;
		i++;
	}
*/