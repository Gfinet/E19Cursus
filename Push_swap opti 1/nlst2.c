/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 21:06:40 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nlst_get_place(t_nlst **a, int cont)
{
	int	place;
	t_nlst *p;

	place = 0;
	p = *a;
	while (p)
	{
		if (p->content == cont)
			return (place);
		place++;
		p = p->next;
	}
	return (0);
}

int	nlst_get_low_big(t_nlst **a, int low_big)
{
	int	num;
	t_nlst *p;

	if (low_big)
		num = -2147483648;
	else
		num = 2147483647;
	p = *a;
	while (p)
	{
		if ((!low_big && p->content < num) || (low_big && p->content > num))
			num = p->content;
		p = p->next;
	}
	return (num);
}

int nlst_get_median(t_nlst **a, int nb_elem)
{
	int lower;
	int bigger;
	t_nlst *p;
	t_nlst *p2;

	p = *a;
	nb_elem -= (nb_elem %2 == 0);
	while (p)
	{
		bigger = 0;
		lower = 0;
		p2 = *a;
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

int nlst_compute_moves(t_nlst **a)
{
	int count;
	t_nlst *p;

	count = 0;
	p = *a;
	while (p)
	{
		count += p->move;
		p = p->next;
	}
	return(count);
}