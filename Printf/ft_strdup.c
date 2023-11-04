/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:33:18 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/04 20:21:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char		*p;
	size_t		len;
	size_t		i;

	len = ft_strlen(src);
	i = 0;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i < len + 1)
	{
		p[i] = src[i];
		i++;
	}
	return (p);
}
