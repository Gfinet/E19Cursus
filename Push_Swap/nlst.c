/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:46:56 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/13 20:10:00 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nlstadd_back(t_nlst **lst, t_nlst *new)
{
	t_nlst	*p;

	if (!*lst)
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

int	ft_nlstclear(t_nlst **lst, void (*del)(void *))
{
	t_nlst	*prev;
	t_nlst	*next_node;

	prev = *lst;
	while (prev)
	{
		next_node = prev->next;
		ft_nlstdelone(prev, del);
		prev = next_node;
	}
	*lst = 0;
	return (0);
}

void	ft_nlstdelone(t_nlst *lst, void (*del)(void *))
{
	if (lst && del)
		free(lst);
}

t_nlst	*ft_nlstnew(int cont)
{
	t_nlst	*new;

	new = (t_nlst *)malloc(sizeof(t_nlst));
	if (!new)
		return (0);
	new->content = cont;
	new->next = 0;
	return (new);
}

int	ft_nlstsize(t_nlst *lst)
{
	int		i;
	t_nlst	*t;

	if (!lst)
		return (0); 
	i = 1;
	t = lst;
	while (t->next)
	{
		t = t->next;
		i++;
	}
	return (i);
}
