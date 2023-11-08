/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:06 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/08 19:18:13 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = -1;
	j = -1;
	if (!p)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	int		j;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	p = (char *)malloc((ft_strlen(s1) + n + 1) * sizeof(char));
	i = -1;
	j = -1;
	if (!p)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j] && n--)
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
