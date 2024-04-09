/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:53:31 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 03:13:43 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//initialyze the t_nlst_head struct

int	nlst_head_init(t_nlst_head **a)
{
	*a = malloc(sizeof(t_nlst_head));
	if (!*a)
		return (0);
	(*a)->first = 0;
	(*a)->lower = 0;
	return (1);
}

//initialyze the result struct
//one is the move count
//two is a flag to know if the pile is sorted

int	res_init(t_2_int **res)
{
	*res = malloc(sizeof(t_2_int));
	if (!res)
		return (0);
	(*res)->one = 0;
	(*res)->two = -1;
	return (1);
}

//get the node wich have the ind position into a

t_nlst	*get_node(t_nlst_head *a, int ind)
{
	t_nlst	*p;

	p = a->first;
	while (ind-- > 1)
		p = p->next;
	return (p);
}

//return the previous node of the value node.

t_nlst	*get_prev(t_nlst_head *a, int val)
{
	t_nlst	*p;
	t_nlst	*prev;

	p = a->first;
	while (p && p->content != val)
	{
		prev = p;
		p = p->next;
	}
	if (!p)
		prev = a->first;
	return (prev);
}
