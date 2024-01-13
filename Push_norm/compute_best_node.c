/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_best_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:51:42 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/13 21:04:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_bigger_lower(t_nlst_head *b, int cur, int a_b)
{
	int		flag;
	t_nlst	*tmp;

	flag = 1;
	tmp = b->first;
	while (tmp && flag)
	{
		if (tmp->content > cur)
			flag = 0;
		tmp = tmp->next;
	}
	if (flag)
		return (nlst_get_place(b, nlst_get_low_big(b, !a_b)));
	tmp = b->first;
	while (tmp && !flag)
	{
		if (tmp->content < cur)
			flag = 1;
		tmp = tmp->next;
	}
	if (!flag)
		return (nlst_get_place(b, nlst_get_low_big(b, !a_b)));
	return (-1);
}

static int	count_modif(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int count)
{
	count = (ft_nlstsize(b) != count) * count;
	count += !count;
	if (count > ft_nlstsize(b) / 2)
		count = ft_nlstsize(b) - count;
	if (nlst_get_place(a, cur->content) < ft_nlstsize(a) / 2)
		count += nlst_get_place(a, cur->content) - 1;
	else
		count += ft_nlstsize(a) - nlst_get_place(a, cur->content) + 1;
	return (count);
}

static int	check_stop(t_nlst *prev, t_nlst *cur, t_nlst *tmp, int a_b)
{
	if (!a_b)
		return (prev->content > cur->content && 
			tmp->content < cur->content);
	else
		return (prev->content < cur->content && 
			tmp->content > cur->content);
}

int	compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b)
{
	int		count;
	t_nlst	*tmp;
	t_nlst	*prev;

	count = check_all_bigger_lower(b, cur->content, a_b);
	if (count == -1)
	{
		count ++;
		tmp = b->first;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
			if (!tmp)
				tmp = b->first;
			if (check_stop(prev, cur, tmp, a_b))
				break ;
			count ++;
		}
	}
	count = count_modif(a, b, cur, count);
	return (count);
}
