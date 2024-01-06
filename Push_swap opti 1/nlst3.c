/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:53:31 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/06 22:51:14 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nlst_head_init(t_nlst_head **a)
{
    *a = malloc(sizeof(t_nlst_head));
    if (!*a)
        return (0);
    (*a)->first = 0;
    (*a)->bigger = 0;
    (*a)->lower = 0;
    (*a)->median = 0;
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

int get_closer(t_nlst_head *a, int b)
{
	int l;
	int bi;
	int m;

	l = b - a->lower;
	m = b - a->median;
	bi = a->bigger - b;
	if (m < 0)
		m *= -1;
	if (l <= m && m < bi)
		return (a->lower);
	if (m <= l && m < bi)
		return (a->median);
	if (bi < m && bi <= l)
		return (a->bigger);
	if (l == m)
		return (a->lower);
	if (m == bi)
		return (a->bigger);
	return (0);
}

int get_last(t_nlst_head *a)
{
	t_nlst *p;

	p = a->first;
	while (p->next)
		p = p->next;
	return (p->content);
}

t_nlst *get_node(t_nlst_head *a, int ind)
{
	t_nlst *p;

	p = a->first;
	while (ind-- > 1)
		p = p->next;
	return (p);
}