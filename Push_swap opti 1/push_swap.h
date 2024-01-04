/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/04 00:51:20 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Printf/libft/libft.h"
# include "./Printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h> ////////////////////////////////////////////////////
# define SEP 32 // 32( ) 10(\n)

typedef struct s_res
{
	int		moves;
	int		sorted;
}	t_res;

t_res	*push_swap(char **argv, int argc);
int		res_init(t_res **res);

typedef struct s_nlst
{
	int				content;
	int				move;
	struct s_nlst	*next;
}	t_nlst;

typedef struct s_nlst_head
{
	int		lower;
	int		bigger;
	int		median;
	t_nlst	*first;
}	t_nlst_head;

void	push(t_nlst_head *a, t_nlst_head *b, int a_b);
void	swap(t_nlst_head *l, t_nlst_head *m, int a_b);
void	rotate(t_nlst_head *l, t_nlst_head *m, int a_b);
void	reverse_rotate(t_nlst_head *l, t_nlst_head *m, int a_b);
void	ps_sort(t_nlst_head *a, t_nlst_head *b);

int		nlst_get_place(t_nlst_head *a, int cont);
int		nlst_get_low_big(t_nlst_head *a, int a_b);
void	ft_nlstadd_back(t_nlst_head *lst, t_nlst *new);
int		ft_nlstclear(t_nlst_head *lst, void (*del)(void *));
void	ft_nlstdelone(t_nlst *lst, void (*del)(void *));
t_nlst	*ft_nlstnew(int cont);
int		ft_nlstsize(t_nlst_head *lst);
int		nlst_get_median(t_nlst_head *a, int nb_elem);
int		nlst_compute_moves(t_nlst_head *a);
void	rot_to_first(t_nlst_head *a, int num, int n, int a_b);
int		nlst_is_need_val(t_nlst_head *a, int x);
int		nlst_head_init(t_nlst_head **a);
int		get_closer(t_nlst_head *a, int b);
int		get_fval(t_nlst_head *a);

int		check_heap(t_nlst **a, int a_b);
int		check_first(t_nlst_head *a, int a_b);
int		check_only_need_rot(t_nlst_head *a, int a_b);
int		check_only_swap(t_nlst_head *a, int size, int a_b);
int		check_swap(t_nlst_head *a, int a_b);

void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b);
int		find_less_move(t_nlst_head *a, t_nlst_head *b);
int		compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur);

#endif