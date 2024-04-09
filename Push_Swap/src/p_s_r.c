/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:29 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 03:13:46 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Push the first node from a to b and print pa or pb with a_b
//0 : pa / 1 : pb 

void	push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	t_nlst	*tmp;

	a->first->move++;
	tmp = b->first;
	b->first = a->first;
	a->first = a->first->next;
	b->first->next = tmp;
	if (!a_b)
		ft_printf("pa%c", SEP);
	else
		ft_printf("pb%c", SEP);
}

//Swap the first and the second node in l and print sa, sb or ss with a_b
//0 : sa / 1 : sb / 2 : ss

void	swap(t_nlst_head *l, t_nlst_head *m, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (ft_nlstsize(l) < 2)
		return ;
	if (m && a_b == 2)
		ft_printf("ss%c", SEP);
	if (l && !m)
		l->first->move++;
	tmp = l->first->next;
	tmp2 = tmp->next;
	l->first->next = tmp2;
	tmp->next = l->first;
	l->first = tmp;
	if (m && a_b == 2)
		swap(m, 0, 2);
	else if (!a_b)
		ft_printf("sa%c", SEP);
	else if (a_b == 1)
		ft_printf("sb%c", SEP);
}

//Rotate the pile l or both piles and print ra, rb or rr with a_b
//0 : ra / 1 : rb / 2 : rr

void	rotate(t_nlst_head *l, t_nlst_head *m, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (ft_nlstsize(l) < 2)
		return ;
	if (m && a_b == 2)
		ft_printf("rr%c", SEP);
	if (l && !m)
		l->first->move++;
	tmp = l->first;
	l->first = tmp->next;
	tmp2 = l->first;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (m && a_b == 2)
		rotate(m, 0, 2);
	else if (!a_b)
		ft_printf("ra%c", SEP);
	else if (a_b == 1)
		ft_printf("rb%c", SEP);
}

//Reverse_rotate the pile l or both piles and print rra, rrb or rrr with a_b
//0 : rra / 1 : rrb / 2 : rrr

void	reverse_rotate(t_nlst_head *a, t_nlst_head *m, int a_b)
{
	t_nlst	*tmp;
	t_nlst	*tmp2;

	if (ft_nlstsize(a) < 2)
		return ;
	if (m && a_b == 2)
		ft_printf("rrr%c", SEP);
	if (a && !m)
		a->first->move++;
	tmp = a->first;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = a->first;
	tmp2->next = NULL;
	a->first = tmp;
	if (m && a_b == 2)
		reverse_rotate(m, 0, 2);
	else if (!a_b)
		ft_printf("rra%c", SEP);
	else if (a_b == 1)
		ft_printf("rrb%c", SEP);
}
