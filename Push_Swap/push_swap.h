/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:48:44 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/12 19:29:51 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./Printf/ft_printf.h"

int		push_swap(char **argv);
void	push(t_list **a, t_list **b);
void	swap(t_list **l);
void	rotate(t_list **l);
void	reverse_rotate(t_list **l);

#endif