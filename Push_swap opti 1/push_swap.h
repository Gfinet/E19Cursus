/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:44 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 21:10:22 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Printf/libft/libft.h"
# include "./Printf/ft_printf.h"
# include <unistd.h>
#include <stdio.h> ////////////////////////////////////////////////////

int		push_swap(char **argv, int argc);

typedef struct s_nlst
{
	int				content;
	int				move;
	struct s_nlst	*next;
}	t_nlst;

void	push(t_nlst **a, t_nlst **b, int a_b);
void	swap(t_nlst **l, int a_b);
void	rotate(t_nlst **l, int a_b);
void	reverse_rotate(t_nlst **l, int a_b);
void	ps_sort(t_nlst **a, t_nlst **b);


int		nlst_get_place(t_nlst **a, int cont);
int		nlst_get_low_big(t_nlst **a, int a_b);
void	ft_nlstadd_back(t_nlst **lst, t_nlst *new);
int		ft_nlstclear(t_nlst **lst, void (*del)(void *));
void	ft_nlstdelone(t_nlst *lst, void (*del)(void *));
t_nlst	*ft_nlstnew(int cont);
int		ft_nlstsize(t_nlst *lst);
int		nlst_get_median(t_nlst **a, int nb_elem);
int 	nlst_compute_moves(t_nlst **a);
void 	rot_to_first(t_nlst **a, int n, int a_b);

int		check_heap(t_nlst **a, int a_b);
int		check_first(t_nlst **a, int a_b);
int		check_only_need_rot(t_nlst **a, int a_b);
int		check_only_swap(t_nlst **a, int size, int a_b);
int		check_swap(t_nlst **a, int a_b);


#endif