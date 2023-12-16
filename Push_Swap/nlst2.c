/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:17:48 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/13 22:26:06 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_place(t_nlst **a, int cont)
{
	int	place;

	place = 0;
	while ((*a))
	{
		if ((*a)->content == cont)
			return (place);
		place++;
		(*a) = (*a)->next;
	}
	return (0);
}

int	get_low(t_nlst **a)
{
	int	low;

	low = 2147483647;
	while ((*a))
	{
		if ((*a)->content < low)
			low = (*a)->content;
		(*a) = (*a)->next;
	}
	return (low);
}