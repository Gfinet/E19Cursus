/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/29 06:39:22 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nlst_get_place(t_nlst_head *a, int cont)
{
	int	place;
	t_nlst *p;

	place = 0;
	p = a->first;
	while (p)
	{
		if (p->content == cont)
			return (place);
		place++;
		p = p->next;
	}
	return (0);
}

int	nlst_get_low_big(t_nlst_head *a, int low_big)
{
	int	num;
	t_nlst *p;

	if (low_big)
		num = -2147483648;
	else
		num = 2147483647;
	p = a->first;
	while (p)
	{
		if ((!low_big && p->content < num) || (low_big && p->content > num))
			num = p->content;
		p = p->next;
	}
	return (num);
}

int nlst_get_median(t_nlst_head *a, int nb_elem)
{
	int lower;
	int bigger;
	t_nlst *p;
	t_nlst *p2;

	p = a->first;
	nb_elem -= (nb_elem %2 == 0);
	while (p)
	{
		bigger = 0;
		lower = 0;
		p2 = a->first;
		while (p2)
		{
			bigger += (p->content < p2->content);
			lower += (p->content > p2->content);
			if (bigger == lower && bigger == nb_elem / 2)
				return (p->content);
			p2 = p2->next;
		}
	p = p->next;
	}
	return (0);
}

int nlst_compute_moves(t_nlst_head *a)
{
	int count;
	t_nlst *p;

	count = 0;
	p = a->first;
	while (p)
	{
		count += p->move;
		p = p->next;
	}
	return(count);
}

int nlst_is_need_val(t_nlst_head *a, int x)
{
	if (x == a->lower || x == a->bigger || x == a->median)
		return (1);
	else
		return (0);
}