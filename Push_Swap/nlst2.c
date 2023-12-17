/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/16 18:49:15 by Gfinet           ###   ########.fr       */
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

int	nlst_get_low(t_nlst **a)
{
	int	low;
	t_nlst *p;

	low = 2147483647;
	p = *a;
	while (p)
	{
		if (p->content < low)
			low = p->content;
		p = p->next;
	}
	return (low);
}