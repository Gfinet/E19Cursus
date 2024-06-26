/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/29 22:04:45 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Printf/ft_printf.h"
# include <unistd.h>
# ifndef SEP
#  define SEP 10 // 32( ) 10(\n)
# endif

typedef struct s_2_int
{
	int	one;
	int	two;
}	t_2_int;

t_2_int	*push_swap(char **argv, int argc);
int		res_init(t_2_int **res);

typedef struct s_nlst
{
	int				content;
	int				move;
	struct s_nlst	*next;
}	t_nlst;

typedef struct s_nlst_head
{
	int		lower;
	t_nlst	*first;
}	t_nlst_head;

//mainc.c
int		parse_arg(int argc, char **argv, char ***nums, int *nb_elem);
int		check_input(char **s, int n_arg, int arg);
int		equal_int(char *s1, char *s2);

//free.c
void	strarray_free(char **p, int flag);

//all_verif.c
int		check_heap(t_nlst *a, int a_b);
int		check_first(t_nlst_head *a, int a_b);
int		check_only_need_rot(t_nlst_head *a, int a_b);
int		check_only_swap(t_nlst_head *a, int size, int a_b);

//compute_best_node.c
int		get_next_place(t_nlst_head *b, t_nlst *cur, int a_b);
int		check_all_bigger_lower(t_nlst_head *b, int cur, int a_b);
int		modif_best(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b);
int		compute_moves(t_nlst_head *a, t_nlst_head *b, t_nlst *cur, int a_b);

//make_less_move.c
int		find_less_move(t_nlst_head *a, t_nlst_head *b, int a_b);
int		get_next(t_nlst_head *b, int val, int a_b);
void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b);

//nlst[ -2-3].c
void	ft_nlstadd_back(t_nlst_head *lst, t_nlst *new);
void	ft_nlstdelone(t_nlst *lst, void (*del)(void *));
int		ft_nlstclear(t_nlst_head *lst, void (*del)(void *));
int		ft_nlstsize(t_nlst_head *lst);

int		nlst_get_place(t_nlst_head *a, int cont);
int		nlst_get_low_big(t_nlst_head *a, int a_b);
int		nlst_compute_moves(t_nlst_head *a);
t_nlst	*ft_nlstnew(int cont);
int		nlst_head_init(t_nlst_head **a);
int		res_init(t_2_int **res);
t_nlst	*get_node(t_nlst_head *a, int ind);
t_nlst	*get_prev(t_nlst_head *a, int val);

//p_s_r.c
void	push(t_nlst_head *a, t_nlst_head *b, int a_b);
void	swap(t_nlst_head *l, t_nlst_head *m, int a_b);
void	rotate(t_nlst_head *l, t_nlst_head *m, int a_b);
void	reverse_rotate(t_nlst_head *l, t_nlst_head *m, int a_b);

//ps_sort.c
void	print_list(t_nlst_head *a, int a_b);
void	rot_to_first(t_nlst_head *a, int num, int n, int a_b);
void	sort_3(t_nlst_head *a, int a_b);
void	pre_sort(t_nlst_head *a, t_nlst_head *b);
void	opti_push(t_nlst_head *a, t_nlst_head *b, int a_b);

//push_swap.c
int		fill_a(t_nlst_head *a, char **arg, int nb_arg);
t_2_int	*push_swap(char **arg, int nb_arg);

#endif