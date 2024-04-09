/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 09:15:23 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include "../inc/push_swap.h"

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*free_all(char **tmp, char **tmp2);
char	*ft_stradd(char *s1, char const *s2);

int	check_input(char **s, int n_arg);
int	is_number(char *s);
int	parse_arg(int argc, char **argv, char ***nums, int *nb_elem);
void	make_move(t_nlst_head *a, t_nlst_head *b, char *move);
int	emule_ps_answer(char **arg, int nb_arg);
#endif