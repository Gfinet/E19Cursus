/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:09:33 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/17 22:54:33 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_nlst	*init_p(t_nlst_head *l, t_nlst *cur, int a_b)
{
	int		next;
	t_nlst	*p;

	if (a_b)
	{
		next = get_next(l, cur->content, a_b);
		p = l->first;
		while (p && p->content != next)
			p = p->next;
	}
	else
	{
		p = l->first;
		if (cur->next)
		{
			while (p->next && p != cur)
				p = p->next;
			p = p->next;
		}
	}
	return (p);
}

static int	*init_imagi_list(t_nlst_head *l, t_nlst *cur, t_nlst *p, int a_b)
{
	int		i;
	int		size;
	int		*m;

	size = ft_nlstsize(l) + ((1 * a_b) - (1 * !a_b));
	m = malloc(sizeof(int) * size);
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

static int	my_free(int *a1, t_nlst_head *a, t_nlst_head *b)
{
	if (a1)
		free(a1);
	return (ft_nlstsize(a) * ft_nlstsize(b));
}

static int	compute_second(int val, int *b2, int size_b, int a_b)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		if (i == 0)
		{
			if ((!a_b && b2[0] < val && val < b2[size_b - 1])
				|| (a_b && b2[0] > val && val > b2[size_b - 1]))
				break ;
		}
		else
		{
			if ((!a_b && b2[i] < val && val < b2[i - 1])
				|| (a_b && b2[i] > val && val > b2[i - 1]))
				break ;
		}

		i++;
	}
	return (i);
}

int	guess_sec(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b)
{
	int		*a2;
	int		*b2;
	int		i;
	int		best;
	int		move_a;

	b2 = init_imagi_list(b, cur, init_p(b, cur, !a_b), !a_b);
	if (!b2)
		return (my_free(0, a, b));
	a2 = init_imagi_list(a, cur, init_p(a, cur, a_b), a_b);
	if (!a2)
		return (my_free(b2, a, b));
	i = 0;
	while (i < ft_nlstsize(a) - 1)
	{
		move_a = i * (i < ((ft_nlstsize(a) - 1)  / 2))
			+ (ft_nlstsize(a) - 1 - i) * (i >= ((ft_nlstsize(a) - 1)  / 2));
		if (compute_second(a2[i], b2, ft_nlstsize(b) + 1, a_b) + move_a < best)
			best = compute_second(a2[i], b2, ft_nlstsize(b) + 1, a_b) + move_a;
		i++;
	}
	free(a2);
	free(b2);
	return (best);
}
