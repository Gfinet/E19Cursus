/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/03 22:39:00 by gfinet           ###   ########.fr       */
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

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*free_all_GNL(char **tmp, char **tmp2);
char	*ft_stradd(char *s1, char const *s2);

#endif