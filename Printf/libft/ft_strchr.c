/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:40:33 by gfinet            #+#    #+#             */
/*   Updated: 2023/10/21 15:43:08 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p;
	size_t	len;

	len = ft_strlen(str);
	p = (char *)str;
	while (p - 1 != &str[len])
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (!c)
		return (p);
	return (0);
}
