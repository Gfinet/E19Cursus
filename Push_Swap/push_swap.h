/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:44 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/16 17:51:33 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Printf/libft/libft.h"
# include "./Printf/ft_printf.h"
#include <stdio.h> ////////////////////////////////////////////////////

int		push_swap(char **argv, int argc);

typedef struct s_nlst
{
	int				content;
	struct s_nlst	*next;
}	t_nlst;

void	push(t_nlst **a, t_nlst **b);
void	swap(t_nlst **l);
void	rotate(t_nlst **l);
void	reverse_rotate(t_nlst **l);
void	ps_sort(t_nlst **a, t_nlst **b);



void	ft_nlstadd_back(t_nlst **lst, t_nlst *new);
int		ft_nlstclear(t_nlst **lst, void (*del)(void *));
void	ft_nlstdelone(t_nlst *lst, void (*del)(void *));
t_nlst	*ft_nlstnew(int cont);
int		ft_nlstsize(t_nlst *lst);




#endif