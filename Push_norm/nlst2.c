/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/13 21:34:16 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nlst_get_place(t_nlst_head *a, int cont)
{
	int		place;
	t_nlst	*p;

	place = 1;
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
	int		num;
	t_nlst	*p;

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

int	nlst_compute_moves(t_nlst_head *a)
{
	int		count;
	t_nlst	*p;

	count = 0;
	p = a->first;
	while (p)
	{
		count += p->move;
		p = p->next;
	}
	return (count);
}
