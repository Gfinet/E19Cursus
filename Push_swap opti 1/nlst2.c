/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/18 20:05:49 by gfinet           ###   ########.fr       */
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