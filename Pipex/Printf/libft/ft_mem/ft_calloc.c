/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:23:32 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/31 19:14:36 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}
