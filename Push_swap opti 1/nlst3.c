/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:53:31 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/07 04:14:59 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nlst_head_init(t_nlst_head **a)
{
    *a = malloc(sizeof(t_nlst_head));
    if (!*a)
        return (0);
    (*a)->first = 0;
    (*a)->lower = 0;
    return (1);
}

int res_init(t_res **res)
{
	*res = malloc(sizeof(t_res));
	if (!res)
		return (0);
	(*res)->moves = 0;
	(*res)->sorted = -1;
	return (1);
}

t_nlst *get_node(t_nlst_head *a, int ind)
{
	t_nlst *p;

	p = a->first;
	while (ind-- > 1)
		p = p->next;
	return (p);
}

t_nlst *get_prev(t_nlst_head *a, int val)
{
	t_nlst *p;
	t_nlst *prev;

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